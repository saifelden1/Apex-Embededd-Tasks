# Week 3 — Hardware Timer Basics & PWM Generation

[![Week](https://img.shields.io/badge/Week-3%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-Timer%20Basics%20%7C%20PWM%20Generation-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--2--adc--pwm-orange.svg)](#)

Welcome to **Week 3** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **Core Timer Hardware Fundamentals**:
   * **Counter Register (`CNT`)**: Counts clock pulses up or down.
   * **Prescaler (`PSC`)**: 16-bit register that divides the input timer clock ($f_{timer\_tick} = \frac{f_{clk}}{PSC + 1}$).
   * **Auto-Reload Register (`ARR`)**: Defines the timer overflow period and determines the PWM base frequency.
   * **Timer Counter Modes**: Up-counting, Down-counting, and Center-aligned counting.
2. **Pulse Width Modulation (PWM) Generation**:
   * **Capture/Compare Register (`CCR`)**: Sets the duty cycle threshold.
   * Output Compare modes (PWM Mode 1 vs PWM Mode 2).
   * Calculating carrier frequency and duty cycle percentage:
     $$\text{PWM Frequency} = \frac{f_{TIM\_CLK}}{(\text{PSC} + 1) \times (\text{ARR} + 1)}$$
     $$\text{Duty Cycle (\%)} = \frac{\text{CCR}}{\text{ARR}} \times 100\%$$
3. **Hands-on Timer Setup in CubeIDE**:
   * Configuring General-Purpose Timer 2 (`TIM2`) Channel 2 on pin `PA1`.
   * Generating a precise 1 kHz PWM square wave.
   * Modulating pulse width dynamically in software via `__HAL_TIM_SET_COMPARE()`.

---

## Daily Operational Guide

* **Day 1 (Monday)**: Watch video lectures explaining Prescaler, Auto-Reload, and Output Compare mechanics.
* **Day 2 (Tuesday)**: Attend live whiteboard session: deriving the mathematical PWM frequency and resolution equations.
* **Day 3 (Wednesday)**: Replicate live lab: setting up TIM2 PWM on PA1 and probing the output on the Proteus virtual oscilloscope.
* **Day 4 (Thursday)**: Office hours for troubleshooting timer clock calculations and APB1 timer multipliers.
* **Day 5 (Friday)**: Complete modular PWM driver (`pwm_led.c` & `pwm_led.h`) to smoothly vary LED brightness.
* **Day 6 (Saturday)**: Submit PWM driver code and oscilloscope waveform captures.
* **Day 7 (Sunday)**: Attend 1-on-1 oral defense review.

---

## Associated Milestone Task
This week prepares you directly for the PWM half of Task 2. Switch to:
```bash
git checkout task-2-adc-pwm
```
Refer to the `task-2-adc-pwm` branch for the combined Potentiometer + PWM task specifications.
