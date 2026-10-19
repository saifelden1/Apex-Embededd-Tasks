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

## Daily Operational Guide & Curated Video Links

* **Day 1 (Monday) — ADC Architecture & Quantization**:
  * 📺 [Master Course (Min 05:06:27 – 05:35:00)](https://www.youtube.com/watch?v=vKyL43qXPpk&t=18387s) — Projects 15 & 18: ADC Control & Servo/Potentiometer
  * Understand 12-bit quantization, $V_{REF}=3.3\text{V}$, and $ADCCLK \le 14\text{ MHz}$ prescaler rule.
  * Calculate voltage conversion: $V = \frac{\text{ADC\_RAW}}{4095} \times 3.3\text{V}$.
* **Day 2 (Tuesday) — Direct Memory Access (DMA) Deep-Dive**:
  * 📺 [DMA All Modes Short](https://www.youtube.com/watch?v=UTYdhF7lxFs)
  * 📺 [DMA Single Mode Short](https://www.youtube.com/watch?v=d0aO6HF2Eu0)
  * 📺 [DMA In Depth](https://www.youtube.com/watch?v=deMF2xu_ASQ)
  * Compare Polling vs Interrupt vs DMA circular mode and understand why DMA offloads the CPU.
* **Day 3 (Wednesday) — Live Session: Task 2 ADC + PWM Pipeline**:
  * 45-min live session: Configuring ADC1 Channel 0 (PA0) and mapping analog reading directly to PWM duty cycle on PA1.
  * Live demonstration of `HAL_ADC_Start()`, `HAL_ADC_GetValue()`, and circular buffer DMA setup (`HAL_ADC_Start_DMA()`).
  * Follow live demo; configure ADC1 in CubeIDE and build with 0 errors.
* **Day 4 (Thursday) — Potentiometer Helper Driver Coding**:
  * Write simple helper driver in `potentiometer.h` & `potentiometer.c` (`POT_Init`, `POT_ReadRaw`, `POT_ReadPercentage`).
  * Map raw 0-4095 count to PWM compare register (`__HAL_TIM_SET_COMPARE`) to dynamically control LED brightness.
* **Day 5 (Friday) — Offline Lab Day**:
  * In-person meeting at team workshop: connect interactive potentiometer in Proteus (or physical breadboard).
  * Observe smooth LED dimming and oscilloscope pulse widening.
* **Day 6 (Saturday) — Submission Deadline (Task 2)**:
  * Submit Task 2 deliverable: code + Proteus demo video + `Template_Report.md` by 11:59 PM.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute check-in: explain why $ADCCLK \le 14\text{ MHz}$, how SAR converts voltage, and how DMA circular mode offloads the CPU.


---

## Associated Milestone Task
Complete the full Task 2 assignment on:
```bash
git checkout task-2-adc-pwm
```
Refer to the `task-2-adc-pwm` branch for complete circuit schematics, potentiometer wiring, and bonus mode rubrics.
