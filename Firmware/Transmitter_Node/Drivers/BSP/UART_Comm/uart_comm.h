/**
 ******************************************************************************
 * @file    uart_comm.h
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular UART Telemetry Communication Protocol Driver.
 ******************************************************************************
 */

#ifndef BSP_UART_COMM_H_
#define BSP_UART_COMM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

#define UART_COMM_START_BYTE   (0xAAU)
#define UART_COMM_END_BYTE     (0x55U)
#define UART_COMM_PACKET_LEN   (8U)

/**
 * @brief Telemetry Payload Data Structure
 */
typedef struct {
    uint8_t  packet_id;
    uint16_t speed_kmh;
    uint16_t voltage_mv;
    uint8_t  status_flag;
} TelemetryData_t;

/**
 * @brief UART Comm Handle
 */
typedef struct {
    UART_HandleTypeDef *huart;
    uint8_t             tx_buffer[UART_COMM_PACKET_LEN];
    uint8_t             rx_buffer[UART_COMM_PACKET_LEN];
    uint8_t             rx_index;
    uint8_t             packet_ready;
} UART_CommHandle_t;

/* Public API */
void    UART_Comm_Init(UART_CommHandle_t *hcomm, UART_HandleTypeDef *huart);
uint8_t UART_Comm_CalculateChecksum(const uint8_t *data, uint8_t len);
HAL_StatusTypeDef UART_Comm_SendTelemetry(UART_CommHandle_t *hcomm, const TelemetryData_t *telemetry);
uint8_t UART_Comm_ParseByte(UART_CommHandle_t *hcomm, uint8_t byte, TelemetryData_t *out_telemetry);

#ifdef __cplusplus
}
#endif

#endif /* BSP_UART_COMM_H_ */
