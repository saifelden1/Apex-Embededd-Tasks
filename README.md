# Apex Racing Team — Embedded Systems Learning Phase

[![Platform](https://img.shields.io/badge/Platform-STM32F103C8T6%20(Blue%20Pill)-blue.svg)](https://www.st.com)
[![IDE](https://img.shields.io/badge/IDE-STM32CubeIDE%20v1.14+-darkgreen.svg)](https://www.st.com/en/development-tools/stm32cubeide.html)
[![Simulation](https://img.shields.io/badge/Simulation-Proteus%208.13+-orange.svg)](https://www.labcenter.com)
[![Language](https://img.shields.io/badge/Language-Embedded%20C-brightgreen.svg)](#)

Welcome to the **Apex Racing Team** Embedded Systems Onboarding & Training Track. This training program is designed to build foundational hands-on proficiency in microcontroller architecture, peripheral interfacing, modular driver development, and hardware-in-the-loop / schematic simulation.

---

## Repository Structure & Branch Map

This repository uses dedicated Git branches for each milestone. Clone the repository and switch to the branch corresponding to your current task:

```bash
git clone https://github.com/saifelden1/Apex-Embededd-Tasks.git
cd Apex-Embededd-Tasks
```

| Branch | Task Name | Key Focus | Target Hardware |
| :--- | :--- | :--- | :--- |
| `main` | **Track Hub** | Guidelines, setup instructions, policies | — |
| `task-1-gpio-led` | **Task 1: GPIO & LED Driver** | Clock tree, Push-Pull GPIO, Modular driver | STM32 Blue Pill + LEDs |
| `task-2-adc-pwm` | **Task 2: ADC & Timer PWM** | Potentiometer sampling, Timer PWM dimming, ADC modes | STM32 Blue Pill + Pot + LED |
| `task-3-uart-display` | **Task 3: Dual-MCU UART & Display** | Cross-board serial telemetry, Display driver | 2x STM32 Blue Pill + Screen |

To switch to a task branch:
```bash
git checkout <branch-name>
```

---

## Training Philosophy & AI Usage Policy

> [!IMPORTANT]
> **AI Usage & Oral Code Defense Policy**
> * Using AI tools (ChatGPT, Claude, Copilot, Gemini, etc.) as learning assistants, documentation summarizers, and debugging aids is **permitted and encouraged**.
> * **However**, submitting code generated without full comprehension is strictly disqualified.
> * **Every applicant will participate in an oral code defense interview where you will be asked to explain and justify every single line of code, register configuration, and HAL API call in your submission.**
> * If you cannot clearly explain why a line exists, how the underlying hardware register responds, or how timing is affected, the task will not be accepted.

---

## Required Submission Package

For each completed task branch, you must provide:

1. **Modular Source Code**:
   * Clean separation between application logic (`Core/Src/main.c`) and hardware peripherals.
   * Dedicated `.h` (header) and `.c` (source) files inside `Drivers/BSP/` for all connected hardware.
2. **Simulation / Hardware Verification Media**:
   * High-resolution screenshots demonstrating the working circuit in **Proteus** (or physical bench).
   * Short recorded demo video (or GIF) showcasing the dynamic functionality (e.g., LED toggling at the expected frequency, PWM changing with pot rotation, UART data streaming to display).
3. **Task Documentation (`README.md` / Report)**:
   * A detailed report (using the provided `Template_Report.md`) documenting:
     * Clock configuration & peripheral settings.
     * Hardware wiring / schematic breakdown.
     * Architectural decisions behind your `.c`/`.h` driver design.
     * Challenges encountered, bugs diagnosed, and the exact steps taken to fix them.

---

## Environment & Toolchain Setup

### 1. Development Environment
* **IDE**: [STM32CubeIDE (v1.14.0 or newer)](https://www.st.com/en/development-tools/stm32cubeide.html).
* **Compiler**: GNU Arm Embedded Toolchain (`arm-none-eabi-gcc`), packaged with CubeIDE.
* **Firmware Package**: STM32Cube FW_F1 (Firmware package for STM32F1 series).

### 2. Simulation Environment
* **Proteus Design Suite**: Proteus 8.13 SP0 or higher.
* Ensure the **STM32F103C8** model is available in your Proteus library.
* Set the microcontroller properties in Proteus to:
  * **Crystal Frequency**: `8MHz` (or `72MHz` internal clock matching your RCC settings).
  * **Program File**: Point directly to your compiled `.hex` output located in `Firmware/Debug/`.

### 3. Physical Hardware (Optional / Bonus)
* STM32F103C8T6 "Blue Pill" development board.
* ST-Link V2 programmer / debugger.
* Solderless breadboard, jumper wires, potentiometers (10kΩ), resistors (220Ω, 330Ω), and LEDs.

---

## General Engineering Directives

* **No Sprawling `main.c`**: Never dump low-level driver logic directly into `main.c`. Keep `main.c` reserved for state initialization and application loop coordination.
* **Defensive Programming**: Check return statuses of HAL initialization routines.
* **Non-Blocking Architecture**: Avoid blocking `HAL_Delay()` wherever timers or state machines can achieve non-blocking execution.
* **Meaningful Git Commits**: Commit regularly as you pass milestones. Write descriptive commit messages.
