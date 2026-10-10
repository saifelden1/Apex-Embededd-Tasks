/**
 ******************************************************************************
 * @file    led.c
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular Board Support Package (BSP) Driver for LEDs.
 ******************************************************************************
 */

#include "led.h"

void LED_Init(LED_Handle_t *hled, GPIO_TypeDef *port, uint16_t pin, LED_ActiveState_t active_level)
{
    if (hled == NULL || port == NULL) {
        return;
    }

    hled->port = port;
    hled->pin = pin;
    hled->active_level = active_level;

    /* Initialize to OFF state */
    LED_Off(hled);
}

void LED_SetState(LED_Handle_t *hled, LED_State_t state)
{
    if (hled == NULL || hled->port == NULL) {
        return;
    }

    hled->current_state = state;

    GPIO_PinState pin_state;

    if (hled->active_level == LED_ACTIVE_HIGH) {
        pin_state = (state == LED_STATE_ON) ? GPIO_PIN_SET : GPIO_PIN_RESET;
    } else {
        /* Active-low: 0 is ON, 1 is OFF */
        pin_state = (state == LED_STATE_ON) ? GPIO_PIN_RESET : GPIO_PIN_SET;
    }

    HAL_GPIO_WritePin(hled->port, hled->pin, pin_state);
}

void LED_On(LED_Handle_t *hled)
{
    LED_SetState(hled, LED_STATE_ON);
}

void LED_Off(LED_Handle_t *hled)
{
    LED_SetState(hled, LED_STATE_OFF);
}

void LED_Toggle(LED_Handle_t *hled)
{
    if (hled == NULL || hled->port == NULL) {
        return;
    }

    if (hled->current_state == LED_STATE_ON) {
        LED_Off(hled);
    } else {
        LED_On(hled);
    }
}
