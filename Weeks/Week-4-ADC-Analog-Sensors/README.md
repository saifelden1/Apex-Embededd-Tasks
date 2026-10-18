# Week 4 — Analog-to-Digital Conversion (ADC) & Sensor Sampling

[![Week](https://img.shields.io/badge/Week-4%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-12--Bit%20ADC%20%7C%20Potentiometer%20%7C%20DMA-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--2--adc--pwm-orange.svg)](#)

Welcome to **Week 4** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **ADC Physical Architecture**:
   * Successive Approximation Register (SAR) conversion principle.
   * Internal Sample & Hold capacitor ($C_{sample}$) and sampling time selection.
   * Maximum ADC clock frequency: $ADCCLK \le 14\text{ MHz}$ (RCC APB2 divider configuration).
   * 12-bit Quantization: $V_{in} = \frac{\text{ADC Count}}{4095} \times V_{REF}$.
2. **Analog Sensor Conditioning**:
   * Source impedance considerations: avoiding signal distortion on high-impedance sensors.
   * Linear mapping formulas: converting raw counts to engineering units (volts, position %, throttle %).
3. **ADC Operational Modes**:
   * **Polling Mode**: Software-triggered blocking conversions (`HAL_ADC_PollForConversion`).
   * **Interrupt Mode**: Non-blocking event callbacks (`HAL_ADC_Start_IT`).
   * **Direct Memory Access (DMA)**: Continuous circular buffer sampling with zero CPU load (`HAL_ADC_Start_DMA`).

---

## Daily Operational Guide

* **Day 1 (Monday)**: Watch video lectures on SAR ADC conversion steps and analog reference voltages.
* **Day 2 (Tuesday)**: Attend live whiteboard session: sampling time vs input impedance calculations and ADC clock limits.
* **Day 3 (Wednesday)**: Live coding lab: configuring ADC1 Channel 0 (PA0) and mapping voltage to PWM duty cycle.
* **Day 4 (Thursday)**: Office hours for debugging floating analog inputs and noisy readings.
* **Day 5 (Friday)**: Complete modular driver implementation (`potentiometer.c` & `potentiometer.h`) and test multi-mode bonus.
* **Day 6 (Saturday)**: Submit Task 2 PR with Proteus screenshots, video demonstration, and `Template_Report.md`.
* **Day 7 (Sunday)**: Attend 1-on-1 oral defense review.

---

## Associated Milestone Task
Complete the full Task 2 assignment on:
```bash
git checkout task-2-adc-pwm
```
Refer to the `task-2-adc-pwm` branch for complete circuit schematics, potentiometer wiring, and bonus mode rubrics.
