/**
 ******************************************************************************
 * @file    potentiometer.h
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular BSP Driver for Analog Potentiometer (ADC Interface).
 ******************************************************************************
 */

#ifndef BSP_POTENTIOMETER_H_
#define BSP_POTENTIOMETER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

#define POT_ADC_RESOLUTION_MAX   (4095.0f) /* 12-bit ADC */
#define POT_VREF_VOLTAGE          (3.3f)    /* 3.3V reference voltage */

/**
 * @brief Potentiometer Driver Handle
 */
typedef struct {
    ADC_HandleTypeDef *hadc;
    uint32_t           channel;
    uint16_t           raw_value;
    float              voltage;
    float              percentage;
} POT_Handle_t;

/**
 * @brief  Initializes the Potentiometer handle.
 * @param  hpot:    Pointer to the Potentiometer handle.
 * @param  hadc:    Pointer to the initialized ADC handle.
 * @param  channel: ADC Channel (e.g. ADC_CHANNEL_0).
 */
void POT_Init(POT_Handle_t *hpot, ADC_HandleTypeDef *hadc, uint32_t channel);

/**
 * @brief  Polls the ADC and reads the raw 12-bit ADC conversion value.
 * @param  hpot: Pointer to the Potentiometer handle.
 * @retval 12-bit raw integer (0 - 4095).
 */
uint16_t POT_ReadRaw(POT_Handle_t *hpot);

/**
 * @brief  Calculates the analog voltage corresponding to the wiper position.
 * @param  hpot: Pointer to the Potentiometer handle.
 * @retval Voltage float in volts (0.0V - 3.3V).
 */
float POT_ReadVoltage(POT_Handle_t *hpot);

/**
 * @brief  Calculates the position of the potentiometer as a percentage (0.0% - 100.0%).
 * @param  hpot: Pointer to the Potentiometer handle.
 * @retval Percentage float (0.0f - 100.0f).
 */
float POT_ReadPercentage(POT_Handle_t *hpot);

#ifdef __cplusplus
}
#endif

#endif /* BSP_POTENTIOMETER_H_ */
