/**
 ******************************************************************************
 * @file    uart_comm.c
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular UART Telemetry Communication Protocol Driver.
 ******************************************************************************
 */

#include "uart_comm.h"
#include <string.h>

void UART_Comm_Init(UART_CommHandle_t *hcomm, UART_HandleTypeDef *huart)
{
    if (hcomm == NULL || huart == NULL) {
        return;
    }

    hcomm->huart = huart;
    hcomm->rx_index = 0;
    hcomm->packet_ready = 0;
    memset(hcomm->rx_buffer, 0, sizeof(hcomm->rx_buffer));
}

uint8_t UART_Comm_CalculateChecksum(const uint8_t *data, uint8_t len)
{
    uint8_t sum = 0;
    for (uint8_t i = 0; i < len; i++) {
        sum ^= data[i];
    }
    return sum;
}

HAL_StatusTypeDef UART_Comm_SendTelemetry(UART_CommHandle_t *hcomm, const TelemetryData_t *telemetry)
{
    if (hcomm == NULL || hcomm->huart == NULL || telemetry == NULL) {
        return HAL_ERROR;
    }

    uint8_t buffer[9];
    buffer[0] = UART_COMM_START_BYTE;
    buffer[1] = telemetry->packet_id;
    buffer[2] = (uint8_t)((telemetry->speed_kmh >> 8) & 0xFF);
    buffer[3] = (uint8_t)(telemetry->speed_kmh & 0xFF);
    buffer[4] = (uint8_t)((telemetry->voltage_mv >> 8) & 0xFF);
    buffer[5] = (uint8_t)(telemetry->voltage_mv & 0xFF);
    buffer[6] = telemetry->status_flag;
    buffer[7] = UART_Comm_CalculateChecksum(&buffer[1], 6);
    buffer[8] = UART_COMM_END_BYTE;

    return HAL_UART_Transmit(hcomm->huart, buffer, sizeof(buffer), 100);
}

uint8_t UART_Comm_ParseByte(UART_CommHandle_t *hcomm, uint8_t byte, TelemetryData_t *out_telemetry)
{
    if (hcomm == NULL || out_telemetry == NULL) {
        return 0;
    }

    if (hcomm->rx_index == 0) {
        if (byte == UART_COMM_START_BYTE) {
            hcomm->rx_buffer[0] = byte;
            hcomm->rx_index = 1;
        }
        return 0;
    }

    hcomm->rx_buffer[hcomm->rx_index++] = byte;

    if (hcomm->rx_index >= 9) {
        hcomm->rx_index = 0;

        if (hcomm->rx_buffer[8] == UART_COMM_END_BYTE) {
            uint8_t calculated_checksum = UART_Comm_CalculateChecksum(&hcomm->rx_buffer[1], 6);
            if (calculated_checksum == hcomm->rx_buffer[7]) {
                out_telemetry->packet_id   = hcomm->rx_buffer[1];
                out_telemetry->speed_kmh   = (uint16_t)((hcomm->rx_buffer[2] << 8) | hcomm->rx_buffer[3]);
                out_telemetry->voltage_mv  = (uint16_t)((hcomm->rx_buffer[4] << 8) | hcomm->rx_buffer[5]);
                out_telemetry->status_flag = hcomm->rx_buffer[6];
                return 1;
            }
        }
    }

    return 0;
}
