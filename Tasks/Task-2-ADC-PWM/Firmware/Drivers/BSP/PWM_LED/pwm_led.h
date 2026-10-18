/**
 ******************************************************************************
 * @file    pwm_led.h
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular BSP Driver for PWM Dimmable LED.
 ******************************************************************************
 */

#ifndef BSP_PWM_LED_H_
#define BSP_PWM_LED_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/**
 * @brief PWM LED Driver Handle
 */
typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t           channel;
    uint32_t           arr_period;
    float              current_duty;
} PWM_LED_Handle_t;

/**
 * @brief  Initializes the PWM LED handle.
 * @param  hled:       Pointer to the PWM LED handle.
 * @param  htim:       Pointer to the initialized hardware Timer handle.
 * @param  channel:    Timer channel (e.g. TIM_CHANNEL_2).
 * @param  arr_period: Auto-reload period value (ARR).
 */
void PWM_LED_Init(PWM_LED_Handle_t *hled, TIM_HandleTypeDef *htim, uint32_t channel, uint32_t arr_period);

/**
 * @brief  Starts PWM signal generation on the configured timer channel.
 * @param  hled: Pointer to the PWM LED handle.
 */
void PWM_LED_Start(PWM_LED_Handle_t *hled);

/**
 * @brief  Stops PWM signal generation.
 * @param  hled: Pointer to the PWM LED handle.
 */
void PWM_LED_Stop(PWM_LED_Handle_t *hled);

/**
 * @brief  Sets the PWM duty cycle as a percentage (0.0% to 100.0%).
 * @param  hled:         Pointer to the PWM LED handle.
 * @param  duty_percent: Duty cycle in percent (0.0f - 100.0f).
 */
void PWM_LED_SetDutyCycle(PWM_LED_Handle_t *hled, float duty_percent);

/**
 * @brief  Sets the raw compare pulse value (CCR register).
 * @param  hled:  Pointer to the PWM LED handle.
 * @param  pulse: Raw pulse compare value (0 to ARR).
 */
void PWM_LED_SetRawPulse(PWM_LED_Handle_t *hled, uint32_t pulse);

#ifdef __cplusplus
}
#endif

#endif /* BSP_PWM_LED_H_ */
