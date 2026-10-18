/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body - Task 1 (GPIO & Modular LED Driver)
 ******************************************************************************
 */

#include "main.h"
#include "led.h"

/* Private variables */
static LED_Handle_t hLedOnboard;
static LED_Handle_t hLedExternal;

/* Private function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();

    /* Initialize Modular LED Drivers */
    /* Onboard LED: PC13 is Active-Low on Blue Pill */
    LED_Init(&hLedOnboard, LED_ONBOARD_GPIO_Port, LED_ONBOARD_Pin, LED_ACTIVE_LOW);

    /* External LED: PA1 is Active-High with 330R resistor to GND */
    LED_Init(&hLedExternal, LED_EXTERNAL_GPIO_Port, LED_EXTERNAL_Pin, LED_ACTIVE_HIGH);

    /* Start with opposite states to demonstrate alternating blink */
    LED_On(&hLedOnboard);
    LED_Off(&hLedExternal);

    /* Infinite loop */
    while (1)
    {
        /* Alternate blinking every 500 ms */
        LED_Toggle(&hLedOnboard);
        LED_Toggle(&hLedExternal);

        HAL_Delay(500);
    }
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
__weak void SystemClock_Config(void)
{
    /* Default clock configuration matching CubeMX generation */
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9; /* 8MHz * 9 = 72MHz */
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

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LED_ONBOARD_GPIO_Port, LED_ONBOARD_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_EXTERNAL_GPIO_Port, LED_EXTERNAL_Pin, GPIO_PIN_RESET);

    /* Configure GPIO pin : LED_ONBOARD_Pin (PC13) */
    GPIO_InitStruct.Pin = LED_ONBOARD_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_ONBOARD_GPIO_Port, &GPIO_InitStruct);

    /* Configure GPIO pin : LED_EXTERNAL_Pin (PA1) */
    GPIO_InitStruct.Pin = LED_EXTERNAL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_EXTERNAL_GPIO_Port, &GPIO_InitStruct);
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}
