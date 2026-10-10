/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Receiver Node (ECU-2) - Task 3 Telemetry Receiver & Display
 ******************************************************************************
 */

#include "main.h"
#include "uart_comm.h"
#include "display_interface.h"

/* Peripheral Handles */
UART_HandleTypeDef huart1;
static UART_CommHandle_t hComm;

/* Single byte buffer for interrupt reception */
static uint8_t s_rx_byte = 0;
static TelemetryData_t s_latest_telemetry = {0};
static volatile uint8_t s_new_packet_flag = 0;

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

    /* Initialize Modules */
    UART_Comm_Init(&hComm, &huart1);
    Display_Init();

    Display_PrintString("APEX TELEMETRY");
    Display_SetCursor(1, 0);
    Display_PrintString("WAITING ECU-1...");

    /* Start interrupt-driven reception */
    HAL_UART_Receive_IT(&huart1, &s_rx_byte, 1);

    /* Infinite loop */
    while (1)
    {
        if (s_new_packet_flag)
        {
            s_new_packet_flag = 0;

            /* Update display with received metrics */
            Display_PrintTelemetry(s_latest_telemetry.speed_kmh,
                                   s_latest_telemetry.voltage_mv,
                                   s_latest_telemetry.status_flag);
        }

        HAL_Delay(50);
    }
}

/**
 * @brief  UART Rx Transfer completed callback in non-blocking mode.
 * @param  huart: Pointer to a UART_HandleTypeDef structure.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        /* Feed incoming byte into state-machine parser */
        if (UART_Comm_ParseByte(&hComm, s_rx_byte, &s_latest_telemetry))
        {
            s_new_packet_flag = 1;
        }

        /* Re-arm interrupt for next byte */
        HAL_UART_Receive_IT(&huart1, &s_rx_byte, 1);
    }
}

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
    __HAL_RCC_GPIOB_CLK_ENABLE();
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}
