/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c - Receiver Node (ECU-2)
 ******************************************************************************
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/* Pin definitions for USART1 */
#define USART1_TX_Pin       GPIO_PIN_9
#define USART1_TX_GPIO_Port GPIOA

#define USART1_RX_Pin       GPIO_PIN_10
#define USART1_RX_GPIO_Port GPIOA

void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
