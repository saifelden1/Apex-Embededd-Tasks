# Task 1 Documentation & Debugging Report

**Candidate Name**: [Your Name]  
**Apex Team Role**: Embedded Systems Applicant / Trainee  
**Submission Date**: YYYY-MM-DD  

---

## 1. System Setup & Architecture

### 1.1 Clock Configuration
* **HSE / HSI Source**: [Describe your RCC configuration, e.g., 8 MHz Crystal with PLL to 72 MHz]
* **SYSCLK Frequency**: [e.g., 72 MHz or 8 MHz]
* **Peripheral Bus Prescalers (AHB / APB1 / APB2)**: [Describe prescalers]

### 1.2 Pin Mapping Table
| Pin | Direction | Mode | Label | Connected Component |
| :--- | :--- | :--- | :--- | :--- |
| `PC13` | Output | Push-Pull / Open Drain | `LED_ONBOARD` | Built-in Blue Pill LED |
| `PA1` | Output | Push-Pull | `LED_EXTERNAL` | External Red LED (via 330Ω) |

---

## 2. Driver Design (`led.h` & `led.c`)

### 2.1 Design Decisions
* Explain how your `LED_Handle_t` structure encapsulates port, pin, and active polarity:
  [Your explanation here]
* Explain how `LED_On()` handles active-low vs active-high without `if/else` clutter in `main.c`:
  [Your explanation here]

---

## 3. Simulation & Verification

### 3.1 Proteus Setup
* Describe how you configured the STM32F103C8 component in Proteus.
* Attach screenshot of the running circuit here:
  `![Proteus Schematic](Simulation/Proteus/screenshot_running.png)`

### 3.2 Video / GIF Verification
* Provide the link or relative path to the demo video:
  `[Demo Video](Simulation/Proteus/demo_video.mp4)`

---

## 4. Challenges Encountered & Debugging Log

| Issue / Bug Encountered | Root Cause | Diagnosis & Solution |
| :--- | :--- | :--- |
| *Example: LED on PC13 stayed ON when set to 1* | *PC13 is Active-Low on Blue Pill* | *Updated driver active_level to LED_ACTIVE_LOW* |
| [Issue 1] | [Cause] | [Fix] |
| [Issue 2] | [Cause] | [Fix] |

---

## 5. Technical Questions & Learning Reflection
1. **What is the purpose of the BSRR and BRR registers compared to ODR?**
   [Your answer here]
2. **Why is it important to use modular `.c` and `.h` drivers rather than calling `HAL_GPIO_WritePin` directly throughout application code?**
   [Your answer here]
