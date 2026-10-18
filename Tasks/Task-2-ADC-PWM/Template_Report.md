# Task 2 Documentation & Debugging Report

**Candidate Name**: [Your Name]  
**Apex Team Role**: Embedded Systems Applicant / Trainee  
**Submission Date**: YYYY-MM-DD  

---

## 1. System Setup & Peripheral Calculations

### 1.1 ADC1 Configuration
* **Resolution**: 12-bit (Counts: 0 to 4095)
* **ADC Clock Prescaler**: [e.g. PCLK2 / 6 = 12 MHz]
* **Sampling Time**: [e.g. 55.5 Cycles]
* **Calculated Conversion Time ($T_{conv}$)**:
  $$T_{conv} = \text{Sampling Time} + 12.5\text{ cycles} = \dots$$

### 1.2 TIM2 PWM Configuration
* **Timer Clock**: [e.g. 72 MHz]
* **Prescaler (PSC)**: [e.g. 71]
* **Auto-Reload (ARR)**: [e.g. 999]
* **Calculated PWM Frequency ($f_{PWM}$)**:
  $$f_{PWM} = \frac{72\text{ MHz}}{(71 + 1) \times (999 + 1)} = 1000\text{ Hz} = 1\text{ kHz}$$

---

## 2. Driver Design (`potentiometer` & `pwm_led`)

### 2.1 Mapping Algorithm
* Explain how the 12-bit raw reading ($0-4095$) was converted to:
  1. Measured Voltage ($0.0\text{ V} - 3.3\text{ V}$):
  2. PWM Pulse Compare Register (`CCR2` from $0$ to $ARR$):

---

## 3. Simulation & Oscilloscope Verification

### 3.1 Proteus Setup
* Attach schematic screenshot showing MCU, Potentiometer, LED, and Oscilloscope:
  `![Proteus Schematic](Simulation/Proteus/screenshot_circuit.png)`

### 3.2 Oscilloscope Waveforms
Attach oscilloscope captures demonstrating:
1. Low Duty Cycle (~10%): `![10% Duty Cycle](Simulation/Proteus/osc_10_percent.png)`
2. Medium Duty Cycle (~50%): `![50% Duty Cycle](Simulation/Proteus/osc_50_percent.png)`
3. High Duty Cycle (~90%): `![90% Duty Cycle](Simulation/Proteus/osc_90_percent.png)`

### 3.3 Dynamic Video Demo
* Link or relative path to demo video:
  `[Demo Video](Simulation/Proteus/demo_video.mp4)`

---

## 4. Bonus Challenge: ADC Multi-Mode Comparison

| ADC Mode | Implementation Method | CPU Involvement / Overhead | Pros & Cons |
| :--- | :--- | :--- | :--- |
| **Polling** | `HAL_ADC_PollForConversion()` | Blocks CPU execution during conversion | Simple, but wastes processor cycles |
| **Interrupt** | `HAL_ADC_Start_IT()` + Callback | Non-blocking; CPU handles ISR context switch | Efficient for periodic single events |
| **DMA** | `HAL_ADC_Start_DMA()` + Circular Buffer | Zero CPU intervention; Direct transfer to RAM | Highest performance; ideal for telemetry |

* Provide code snippets or description of how you implemented the bonus mode(s):
  [Your explanation here]

---

## 5. Challenges Encountered & Debugging Log

| Issue / Bug Encountered | Root Cause | Diagnosis & Solution |
| :--- | :--- | :--- |
| *Example: LED did not change brightness* | *Forgot to call HAL_TIM_PWM_Start()* | *Added PWM_LED_Start() in initialization* |
| [Issue 1] | [Cause] | [Fix] |
| [Issue 2] | [Cause] | [Fix] |
