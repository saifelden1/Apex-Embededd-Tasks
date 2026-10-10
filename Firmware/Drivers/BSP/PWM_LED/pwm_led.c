/**
 ******************************************************************************
 * @file    pwm_led.c
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular BSP Driver for PWM Dimmable LED.
 ******************************************************************************
 */

#include "pwm_led.h"

void PWM_LED_Init(PWM_LED_Handle_t *hled, TIM_HandleTypeDef *htim, uint32_t channel, uint32_t arr_period)
{
    if (hled == NULL || htim == NULL) {
        return;
    }

    hled->htim = htim;
    hled->channel = channel;
    hled->arr_period = arr_period;
    hled->current_duty = 0.0f;

    /* Initialize pulse to 0 (OFF) */
    PWM_LED_SetRawPulse(hled, 0);
}

void PWM_LED_Start(PWM_LED_Handle_t *hled)
{
    if (hled == NULL || hled->htim == NULL) {
        return;
    }

    HAL_TIM_PWM_Start(hled->htim, hled->channel);
}

void PWM_LED_Stop(PWM_LED_Handle_t *hled)
{
    if (hled == NULL || hled->htim == NULL) {
        return;
    }

    HAL_TIM_PWM_Stop(hled->htim, hled->channel);
}

void PWM_LED_SetDutyCycle(PWM_LED_Handle_t *hled, float duty_percent)
{
    if (hled == NULL || hled->htim == NULL) {
        return;
    }

    /* Clamp between 0.0% and 100.0% */
    if (duty_percent < 0.0f) {
        duty_percent = 0.0f;
    } else if (duty_percent > 100.0f) {
        duty_percent = 100.0f;
    }

    hled->current_duty = duty_percent;

    /* Calculate CCR pulse value */
    uint32_t pulse = (uint32_t)((duty_percent / 100.0f) * (float)hled->arr_period);
    PWM_LED_SetRawPulse(hled, pulse);
}

void PWM_LED_SetRawPulse(PWM_LED_Handle_t *hled, uint32_t pulse)
{
    if (hled == NULL || hled->htim == NULL) {
        return;
    }

    if (pulse > hled->arr_period) {
        pulse = hled->arr_period;
    }

    __HAL_TIM_SET_COMPARE(hled->htim, hled->channel, pulse);
}
