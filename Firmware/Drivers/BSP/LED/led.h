/**
 ******************************************************************************
 * @file    led.h
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular Board Support Package (BSP) Driver for LEDs.
 ******************************************************************************
 */

#ifndef BSP_LED_H_
#define BSP_LED_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/**
 * @brief Active logic state of the LED
 */
typedef enum {
    LED_ACTIVE_LOW  = 0U, /* Pin LOW turns the LED ON (e.g. onboard Blue Pill PC13) */
    LED_ACTIVE_HIGH = 1U  /* Pin HIGH turns the LED ON (standard configuration) */
} LED_ActiveState_t;

/**
 * @brief Logical state of the LED
 */
typedef enum {
    LED_STATE_OFF = 0U,
    LED_STATE_ON  = 1U
} LED_State_t;

/**
 * @brief LED Driver instance handle
 */
typedef struct {
    GPIO_TypeDef       *port;          /* GPIO Port (GPIOA, GPIOB, GPIOC, etc.) */
    uint16_t           pin;           /* GPIO Pin (GPIO_PIN_0 .. GPIO_PIN_15) */
    LED_ActiveState_t  active_level;  /* Active polarity */
    LED_State_t        current_state; /* Cached operational state */
} LED_Handle_t;

/* Public API Functions */

/**
 * @brief  Initializes an LED handle and forces the LED to the OFF state.
 * @param  hled: Pointer to the LED handle.
 * @param  port: GPIO Port pointer.
 * @param  pin:  GPIO Pin mask.
 * @param  active_level: Active High or Active Low.
 */
void LED_Init(LED_Handle_t *hled, GPIO_TypeDef *port, uint16_t pin, LED_ActiveState_t active_level);

/**
 * @brief  Explicitly sets the logical state (ON or OFF) of the LED.
 * @param  hled:  Pointer to the LED handle.
 * @param  state: Target state (LED_STATE_ON or LED_STATE_OFF).
 */
void LED_SetState(LED_Handle_t *hled, LED_State_t state);

/**
 * @brief  Turns ON the specified LED taking polarity into account.
 * @param  hled: Pointer to the LED handle.
 */
void LED_On(LED_Handle_t *hled);

/**
 * @brief  Turns OFF the specified LED taking polarity into account.
 * @param  hled: Pointer to the LED handle.
 */
void LED_Off(LED_Handle_t *hled);

/**
 * @brief  Toggles the state of the specified LED.
 * @param  hled: Pointer to the LED handle.
 */
void LED_Toggle(LED_Handle_t *hled);

#ifdef __cplusplus
}
#endif

#endif /* BSP_LED_H_ */
