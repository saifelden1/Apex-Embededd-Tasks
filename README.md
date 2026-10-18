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

## Daily Operational Guide & Curated Video Links

* **Day 1 (Monday) — Timer Architecture & Prescalers**:
  * 📺 [Master Course (Min 04:19:48 – 04:42:43)](https://www.youtube.com/watch?v=vKyL43qXPpk&t=15588s) — Projects 11 & 12: Prescaler & ARR
  * 📺 [Timer Video 1: Timer Basics](https://www.youtube.com/watch?v=DyyYaGU4biY)
  * 📺 [Timers Playlist (Videos 1-2)](https://www.youtube.com/playlist?list=PLfIJKC1ud8gjLZBzjE3kKBMDEH_lUc428)
  * Calculate PSC and ARR for 1 kHz at 72 MHz clock ($PSC=71, ARR=999$).
* **Day 2 (Tuesday) — Timer Modes & Timer Interrupts**:
  * 📺 [Timer Video 2: Concepts](https://www.youtube.com/watch?v=4qjRQL6MVRo) & [Timer Video 3: Registers](https://www.youtube.com/watch?v=RZ0uszK2PMo)
  * 📺 [Timers & Timer Interrupts](https://www.youtube.com/watch?v=VfbW6nfG4kw)
  * 📺 [Timers Playlist (Videos 3-4)](https://www.youtube.com/playlist?list=PLfIJKC1ud8gjLZBzjE3kKBMDEH_lUc428)
  * Understand Up/Down/Center-aligned counting and timer overflow events.
* **Day 3 (Wednesday) — Live Session: PWM Signal Generation**:
  * 45-min live session: Configuring TIM2 Channel 2 on PA1 in CubeIDE for 1 kHz PWM.
  * 📺 [Master Course PWM (Min 04:42:43 – 05:14:00)](https://www.youtube.com/watch?v=vKyL43qXPpk&t=16963s) — Projects 13 & 16: PWM & LED Dimming
  * 📺 [Dedicated PWM Guide](https://www.youtube.com/watch?v=AjN58ceQaF4)
  * 📺 [Timers Playlist (Video 5)](https://www.youtube.com/playlist?list=PLfIJKC1ud8gjLZBzjE3kKBMDEH_lUc428)
* **Day 4 (Thursday) — Helper Driver Coding**:
  * Write simple helper functions in `pwm_led.h` & `pwm_led.c` (`PWM_LED_Init`, `PWM_LED_SetDutyCycle`).
  * Use `__HAL_TIM_SET_COMPARE()` to dynamically vary the pulse width.
* **Day 5 (Friday) — Offline Lab Day**:
  * Meet mentor at team workshop: connect Virtual Oscilloscope to PA1 in Proteus.
  * Observe square wave expanding and shrinking at 25%, 50%, 75% duty cycle.
* **Day 6 (Saturday) — Submission Deadline**:
  * Submit PWM driver code and oscilloscope captures/demo video by 11:59 PM.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute check-in: explain the PWM equation ($f = \frac{f_{clk}}{(PSC+1)(ARR+1)}$) and how CCR controls duty cycle.


---

## Associated Milestone Task
This week prepares you directly for the PWM half of Task 2. Switch to:
```bash
git checkout task-2-adc-pwm
```
Refer to the `task-2-adc-pwm` branch for the combined Potentiometer + PWM task specifications.
