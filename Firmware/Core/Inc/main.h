/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file - Task 2 (ADC & Timer PWM)
 ******************************************************************************
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/* Pin Definitions */
#define POT_ANALOG_IN_Pin       GPIO_PIN_0
#define POT_ANALOG_IN_GPIO_Port GPIOA

#define PWM_LED_OUT_Pin         GPIO_PIN_1
#define PWM_LED_OUT_GPIO_Port   GPIOA

/* Timer PWM Constants */
#define PWM_TIMER_PRESCALER     (71U)   /* 72 MHz / (71 + 1) = 1 MHz clock */
#define PWM_TIMER_ARR           (999U)  /* Period = 1000 us -> 1 kHz PWM */

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
