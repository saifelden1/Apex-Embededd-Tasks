# Task 2 — Analog Potentiometer Sampling via ADC & LED Dimming via Timer PWM

[![Target](https://img.shields.io/badge/Target-STM32F103C8T6%20(Blue%20Pill)-blue.svg)](#)
[![Peripherals](https://img.shields.io/badge/Peripherals-ADC1%20%7C%20TIM2%20PWM-brightgreen.svg)](#)
[![Simulation](https://img.shields.io/badge/Simulation-Proteus%208-orange.svg)](#)

---

## Objective
In motorsport embedded systems (such as racecar telemetry and throttle controllers), analog sensors (throttle position sensors, suspension potentiometers, brake pressure transducers) must be continuously sampled, mapped, and used to drive actuators or diagnostic indicators.

The goal of this task is to configure the **STM32F103C8T6** to:
1. Sample an analog potentiometer voltage using **ADC1** (12-bit resolution).
2. Generate a hardware **Pulse Width Modulation (PWM)** signal using an internal hardware timer (**TIM2 Channel 2**).
3. Map the sampled analog input dynamically to the PWM duty cycle to smoothly modulate LED brightness.
4. Encapsulate all logic into modular **Board Support Package (BSP)** drivers (`potentiometer.h/.c` and `pwm_led.h/.c`).
5. **Bonus Challenge**: Implement and compare ADC in **Polling**, **Interrupt**, and **DMA** modes.

---

## Hardware Specifications & Pin Mapping

| Peripheral | MCU Pin | Function | Configuration Details |
| :--- | :--- | :--- | :--- |
| **Potentiometer (Analog Input)** | `PA0` | `ADC1_IN0` | 12-bit Resolution (`0` to `4095`), 0.0V to 3.3V range |
| **Dimmable LED (PWM Output)** | `PA1` | `TIM2_CH2` | PWM Generation, 1 kHz carrier frequency |

> [!CAUTION]
> **Voltage Constraint**: STM32 ADC inputs are rated for a maximum of **+3.3V (V_DDA)**. Do **NOT** connect a 5V supply rail to the potentiometer in physical hardware, as this can destroy the analog input pins. Always power the potentiometer from the MCU's `+3.3V` rail.

---

## Technical Milestones

### Milestone 1: ADC1 Configuration in STM32CubeIDE
1. Enable `ADC1` Channel 0 on `PA0`.
2. Configure ADC parameters:
   * **Data Alignment**: Right alignment.
   * **Resolution**: 12-bit (`0` to `4095` counts).
   * **Scan Conversion Mode**: Disabled (single channel).
   * **Continuous Conversion Mode**: Enabled (or software-triggered).
   * **Sampling Time**: `55.5 Cycles` or `239.5 Cycles` for impedance stabilization.
   * **Clock Prescaler**: Ensure `PCLK2 / 6` or `PCLK2 / 8` so $ADCCLK \le 14\text{ MHz}$ (STM32F1 hardware specification limit).

### Milestone 2: Hardware Timer PWM Configuration (TIM2 Channel 2)
1. Configure `TIM2` Channel 2 as `PWM Generation CH2` on pin `PA1`.
2. Clock calculation for a **1 kHz** PWM carrier frequency (assuming 72 MHz SYSCLK / APB1 Timer clock = 72 MHz):
   $$\text{Timer Frequency} = \frac{\text{Clock}}{(\text{PSC} + 1) \times (\text{ARR} + 1)}$$
   * **Prescaler (PSC)**: `71` $\rightarrow$ Timer clock ticks at $72\text{ MHz} / (71 + 1) = 1\text{ MHz}$ ($1\ \mu\text{s}$ per tick).
   * **Auto-Reload Register (ARR)**: `999` $\rightarrow$ Period $= 1000\ \mu\text{s} = 1\text{ ms}$ ($1\text{ kHz}$).
   * **Pulse (CCR2)**: Initialized to `0`. Range: `0` to `999` ($0\%$ to $100\%$ duty cycle).

### Milestone 3: Modular BSP Driver Design

#### 1. Potentiometer Driver (`Drivers/BSP/Potentiometer/potentiometer.h` & `potentiometer.c`)
```c
typedef struct {
    ADC_HandleTypeDef *hadc;
    uint32_t           channel;
    uint16_t           raw_value;
    float              voltage;
    float              percentage;
} POT_Handle_t;

void     POT_Init(POT_Handle_t *hpot, ADC_HandleTypeDef *hadc, uint32_t channel);
uint16_t POT_ReadRaw(POT_Handle_t *hpot);
float    POT_ReadVoltage(POT_Handle_t *hpot);
float    POT_ReadPercentage(POT_Handle_t *hpot);
```

#### 2. PWM LED Driver (`Drivers/BSP/PWM_LED/pwm_led.h` & `pwm_led.c`)
```c
typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t           channel;
    uint32_t           arr_period;
    float              current_duty;
} PWM_LED_Handle_t;

void PWM_LED_Init(PWM_LED_Handle_t *hled, TIM_HandleTypeDef *htim, uint32_t channel, uint32_t arr_period);
void PWM_LED_Start(PWM_LED_Handle_t *hled);
void PWM_LED_Stop(PWM_LED_Handle_t *hled);
void PWM_LED_SetDutyCycle(PWM_LED_Handle_t *hled, float duty_percent);
void PWM_LED_SetRawPulse(PWM_LED_Handle_t *hled, uint32_t pulse);
```

### Milestone 4: Application Integration (`main.c`)
In `main.c`:
1. Initialize the potentiometer handle and start PWM generation.
2. Inside the main loop:
   * Read analog value from potentiometer.
   * Map raw reading ($0 - 4095$) or percentage ($0.0 - 100.0\%$) to PWM duty cycle.
   * Update PWM compare register (`CCR2`).
   * Smoothly observe brightness changes.

---

## Bonus Challenge: ADC Multi-Mode Architecture

Implement and document the differences between the 3 ADC sampling modes:

| Mode | Mechanism | CPU Load | Typical Use Case |
| :--- | :--- | :--- | :--- |
| **1. Polling Mode** | `HAL_ADC_Start()`, `HAL_ADC_PollForConversion()` | **High (Blocking)** | Low-priority diagnostic checks, startup self-tests |
| **2. Interrupt Mode** | `HAL_ADC_Start_IT()`, callback `HAL_ADC_ConvCpltCallback()` | **Medium (Non-blocking)** | Event-driven periodic sensor triggers |
| **3. DMA Mode** | `HAL_ADC_Start_DMA()` continuous circular transfer | **Zero CPU Overhead** | High-speed telemetry, multi-channel sensor arrays |

> [!TIP]
> To achieve the bonus, implement code branches or preprocessor directives (`#define ADC_MODE_POLLING`, `ADC_MODE_IT`, `ADC_MODE_DMA`) and document the CPU timing differences in your report!

---

## Oral Code Defense Preparation (Interview Topics)

Be prepared to answer the following questions during your oral code defense:
1. **ADC Max Clock Frequency**: Why must the ADC clock on the STM32F103 not exceed 14 MHz? What happens if you run the APB2 clock at 72 MHz and set the ADC prescaler to `/2` or `/4`?
2. **Successive Approximation (SAR)**: How does a SAR ADC physically convert an analog voltage into a digital word? What role does the sample-and-hold capacitor play?
3. **PWM Frequency Calculation**: Show the mathematical formula connecting Timer input clock, Prescaler, ARR, and output PWM frequency. Why is 1 kHz chosen for LED dimming rather than 10 Hz or 100 kHz?
4. **DMA Ring Buffering**: Why is DMA continuous circular mode preferred for multi-channel sensor acquisition over polling?

---

## Required Deliverables

1. **Source Code**:
   * Complete `Firmware/` project including `potentiometer.h/.c` and `pwm_led.h/.c`.
2. **Simulation / Hardware Media**:
   * Proteus screenshot showing the circuit with the interactive potentiometer and the **Virtual Oscilloscope** displaying the PWM square wave at different duty cycles.
   * Short video/GIF demonstrating the potentiometer knob turning and the LED brightness (and oscilloscope wave) responding smoothly.
3. **Task Documentation Report**:
   * Completed [`Template_Report.md`](Template_Report.md) with calculations, screenshots, bug fixes, and bonus mode analysis.
