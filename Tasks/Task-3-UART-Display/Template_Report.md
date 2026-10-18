# Task 3 Documentation & Debugging Report

**Candidate Name**: [Your Name]  
**Apex Team Role**: Embedded Systems Applicant / Trainee  
**Submission Date**: YYYY-MM-DD  

---

## 1. System Setup & Communication Architecture

### 1.1 UART Peripheral Configuration
* **USART Peripheral**: USART1 (or USART2)
* **Baud Rate**: 115200 bps
* **Data Bits / Stop Bits / Parity**: 8 Bits, 1 Stop Bit, No Parity (8N1)
* **Oversampling**: 16x
* **Baud Rate Error Calculation**:
  $$\text{USARTDIV} = \frac{f_{PCLK}}{16 \times \text{Baud Rate}} = \dots$$

### 1.2 Telemetry Packet Protocol Details
* **Start Byte**: `0xAA`
* **End Byte**: `0x55`
* **Checksum Method**: [Describe XOR or Sum checksum formula implemented]
* **Payload Field Breakdown**:
  [Describe fields: Speed, Voltage, Status]

---

## 2. Driver Design

### 2.1 UART Packet Parser State Machine
* Describe your reception state machine (e.g. `STATE_WAIT_START` $\rightarrow$ `STATE_READ_ID` $\rightarrow$ `STATE_READ_DATA` $\rightarrow$ `STATE_VERIFY_CRC`):
  [Your explanation here]

### 2.2 Modular Display Abstraction
* How did you structure the `display_interface.h` abstraction to isolate display hardware specifics from business logic?
  [Your explanation here]

---

## 3. Simulation & Oscilloscope / Virtual Terminal Verification

### 3.1 Proteus Dual-MCU Setup
* Attach schematic screenshot showing both STM32 microcontrollers, the serial link, and the display:
  `![Dual MCU Proteus Schematic](Simulation/Proteus/screenshot_dual_mcu.png)`

### 3.2 Virtual Terminal Log
* Attach screenshot showing the hex/ASCII data stream captured on the Proteus Virtual Terminal:
  `![Virtual Terminal Log](Simulation/Proteus/screenshot_terminal.png)`

### 3.3 Dynamic Video Demo
* Link or relative path to demo video showing continuous transmission and screen updates:
  `[Demo Video](Simulation/Proteus/demo_video.mp4)`

---

## 4. Challenges Encountered & Debugging Log

| Issue / Bug Encountered | Root Cause | Diagnosis & Solution |
| :--- | :--- | :--- |
| *Example: Display froze after 5 seconds* | *Blocking UART call starving display refresh loop* | *Switched to interrupt-driven reception (`HAL_UART_Receive_IT`)* |
| [Issue 1] | [Cause] | [Fix] |
| [Issue 2] | [Cause] | [Fix] |
