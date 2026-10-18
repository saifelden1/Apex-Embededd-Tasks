/**
 ******************************************************************************
 * @file    display_interface.h
 * @author  Apex Racing Team - Embedded Division
 * @brief   Abstract Hardware-Independent Display Driver Interface.
 *          Provides unified display primitives so the physical screen model
 *          (HD44780 Parallel, I2C LCD, SSD1306 OLED, or Virtual Terminal)
 *          can be swapped without altering telemetry application logic.
 ******************************************************************************
 */

#ifndef BSP_DISPLAY_INTERFACE_H_
#define BSP_DISPLAY_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

/**
 * @brief  Initializes the display peripheral and clears the screen.
 */
void Display_Init(void);

/**
 * @brief  Clears all content on the display.
 */
void Display_Clear(void);

/**
 * @brief  Positions the display cursor.
 * @param  row: Line/Row number (0-indexed).
 * @param  col: Column number (0-indexed).
 */
void Display_SetCursor(uint8_t row, uint8_t col);

/**
 * @brief  Prints a null-terminated string at the current cursor position.
 * @param  str: Pointer to string.
 */
void Display_PrintString(const char *str);

/**
 * @brief  Formats and prints structured vehicle telemetry on the display.
 * @param  speed_kmh:  Vehicle speed in km/h.
 * @param  voltage_mv: Battery voltage in millivolts.
 * @param  status:     Status byte or operational state.
 */
void Display_PrintTelemetry(uint16_t speed_kmh, uint16_t voltage_mv, uint8_t status);

#ifdef __cplusplus
}
#endif

#endif /* BSP_DISPLAY_INTERFACE_H_ */
