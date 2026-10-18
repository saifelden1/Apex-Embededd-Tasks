/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Transmitter Node (ECU-1) - Task 3 Telemetry Generator
 ******************************************************************************
 */

#include "main.h"
#include "uart_comm.h"

/* Peripheral Handles */
UART_HandleTypeDef huart1;
static UART_CommHandle_t hComm;

/* Function Prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);

/**
 * @brief  Application entry point.
 * @retval int
 */
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();

    /* Initialize UART Communication Module */
    UART_Comm_Init(&hComm, &huart1);

    TelemetryData_t telemetry;
    telemetry.packet_id = 0;
    telemetry.speed_kmh = 45;      /* Simulated starting speed */
    telemetry.voltage_mv = 12600;  /* Simulated battery voltage: 12.6V */
    telemetry.status_flag = 0x01;  /* Operational flag */

    /* Infinite loop */
    while (1)
    {
        /* Simulate varying telemetry values */
        telemetry.packet_id++;
        telemetry.speed_kmh = (telemetry.speed_kmh + 5) % 180;
        telemetry.voltage_mv = 12600 - (telemetry.packet_id % 500);

        /* Send structured telemetry packet */
        UART_Comm_SendTelemetry(&hComm, &telemetry);

        /* Transmit at 5 Hz (every 200ms) */
        HAL_Delay(200);
    }
}

/**
 * @brief USART1 Initialization Function (115200 8N1)
 */
static void MX_USART1_UART_Init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }
}

__weak void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}
