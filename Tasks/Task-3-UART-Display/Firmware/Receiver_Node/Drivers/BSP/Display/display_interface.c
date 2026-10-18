/**
 ******************************************************************************
 * @file    display_interface.c
 * @author  Apex Racing Team - Embedded Division
 * @brief   Abstract Hardware-Independent Display Driver Implementation.
 *          Contains implementation hooks ready to interface with HD44780,
 *          I2C PCF8574 backpack, SSD1306, or debug UART Virtual Terminal.
 ******************************************************************************
 */

#include "display_interface.h"
#include <stdio.h>
#include <string.h>

/* Internal display configuration state */
static uint8_t s_cursor_row = 0;
static uint8_t s_cursor_col = 0;

void Display_Init(void)
{
    /* Hardware Initialization Hook:
     * When hardware display model is selected:
     * - For 16x2 Parallel: initialize GPIO data/control pins (RS, EN, D4-D7).
     * - For I2C LCD: initialize I2C peripheral and send PCF8574 init sequence.
     * - For SSD1306: initialize SPI/I2C and write display configuration registers.
     */
    Display_Clear();
}

void Display_Clear(void)
{
    s_cursor_row = 0;
    s_cursor_col = 0;
    /* Send Hardware Clear Command (e.g., 0x01 for HD44780) */
}

void Display_SetCursor(uint8_t row, uint8_t col)
{
    s_cursor_row = row;
    s_cursor_col = col;
    /* Send DDRAM Address Set Command to physical hardware */
}

void Display_PrintString(const char *str)
{
    if (str == NULL) {
        return;
    }

    /* Hardware character transmission loop */
    while (*str) {
        /* Write single character to display hardware */
        str++;
    }
}

void Display_PrintTelemetry(uint16_t speed_kmh, uint16_t voltage_mv, uint8_t status)
{
    char line1_buffer[20];
    char line2_buffer[20];

    float voltage_v = (float)voltage_mv / 1000.0f;

    /* Line 1: Speed and Status */
    snprintf(line1_buffer, sizeof(line1_buffer), "SPD: %3u km/h", speed_kmh);
    Display_SetCursor(0, 0);
    Display_PrintString(line1_buffer);

    /* Line 2: Voltage */
    snprintf(line2_buffer, sizeof(line2_buffer), "BAT: %4.1fV ST:%02X", voltage_v, status);
    Display_SetCursor(1, 0);
    Display_PrintString(line2_buffer);
}
