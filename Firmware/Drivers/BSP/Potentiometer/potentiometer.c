/**
 ******************************************************************************
 * @file    potentiometer.c
 * @author  Apex Racing Team - Embedded Division
 * @brief   Modular BSP Driver for Analog Potentiometer (ADC Interface).
 ******************************************************************************
 */

#include "potentiometer.h"

void POT_Init(POT_Handle_t *hpot, ADC_HandleTypeDef *hadc, uint32_t channel)
{
    if (hpot == NULL || hadc == NULL) {
        return;
    }

    hpot->hadc = hadc;
    hpot->channel = channel;
    hpot->raw_value = 0;
    hpot->voltage = 0.0f;
    hpot->percentage = 0.0f;
}

uint16_t POT_ReadRaw(POT_Handle_t *hpot)
{
    if (hpot == NULL || hpot->hadc == NULL) {
        return 0;
    }

    /* Start ADC Conversion */
    HAL_ADC_Start(hpot->hadc);

    /* Poll with reasonable timeout (10 ms) */
    if (HAL_ADC_PollForConversion(hpot->hadc, 10) == HAL_OK) {
        hpot->raw_value = (uint16_t)HAL_ADC_GetValue(hpot->hadc);
    }

    HAL_ADC_Stop(hpot->hadc);

    return hpot->raw_value;
}

float POT_ReadVoltage(POT_Handle_t *hpot)
{
    uint16_t raw = POT_ReadRaw(hpot);
    hpot->voltage = ((float)raw / POT_ADC_RESOLUTION_MAX) * POT_VREF_VOLTAGE;
    return hpot->voltage;
}

float POT_ReadPercentage(POT_Handle_t *hpot)
{
    uint16_t raw = POT_ReadRaw(hpot);
    hpot->percentage = ((float)raw / POT_ADC_RESOLUTION_MAX) * 100.0f;
    return hpot->percentage;
}
