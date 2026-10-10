/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 ******************************************************************************
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/* Exported pin definitions */
#define LED_EXTERNAL_Pin       GPIO_PIN_1
#define LED_EXTERNAL_GPIO_Port GPIOA

#define LED_ONBOARD_Pin        GPIO_PIN_13
#define LED_ONBOARD_GPIO_Port  GPIOC

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
