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

### 6-Week Curriculum Roadmap & Materials
| Week | Module | Assigned Videos | Core Focus Areas | Local Directory | Branch |
| :--- | :--- | :---: | :--- | :--- | :--- |
| **Week 1** | Build Pipeline & Git | **2 Videos** (~45m) | The 4 GCC Stages (-E, -S, -c, -o), Makefile & CMake Brief, Hands-on CLI Lab (Lab/), Git & AI Policy | [Weeks/Week-1-GPIO-Arch/](file:///d:/APEXALL/EmbdeddSystem/Weeks/Week-1-GPIO-Arch/) | week-1-gpio-arch |
| **Week 2** | Silicon Arch & GPIOs | **5 Videos** (~1.5h) | Cortex-M3 Memory Map, Bus Matrix (AHB/APB), Push-Pull vs Open-Drain, Active-Low LEDs, SWD Debugging & Button | [Weeks/Week-2-Clocks-Debug-NVIC/](file:///d:/APEXALL/EmbdeddSystem/Weeks/Week-2-Clocks-Debug-NVIC/) | week-2-clocks-debug-nvic |
| **Week 3** | Timers & PWM Basics | **7 Videos** (~2.0h) | Hardware Timer Registers (CNT, PSC, ARR), 1 kHz PWM Carrier Generation, Duty Cycle Output Compare (CCR) | [`Weeks/Week-3-Timers-PWM-Basics/`](file:///d:/APEXALL/EmbdeddSystem/Weeks/Week-3-Timers-PWM-Basics/) | `week-3-timers-pwm-basics` |
| **Week 4** | 12-Bit ADC & DMA | **4 Videos** (~1.2h) | 12-Bit SAR ADC (0-4095), 14 MHz ADCCLK Limit, Potentiometer Sampling, Polling vs Interrupt vs DMA Circular Mode | [`Weeks/Week-4-ADC-Analog-Sensors/`](file:///d:/APEXALL/EmbdeddSystem/Weeks/Week-4-ADC-Analog-Sensors/) | `week-4-adc-analog-sensors` |
| **Week 5** | UART Deep-Dive & I2C | **8 Videos** (~2.2h) | UART 115200 8N1 Interrupt Reception, Ring Buffers, Telemetry Packets (0xAA/0x55/XOR), Fast I2C Theory & Pull-ups | [`Weeks/Week-5-Serial-UART-I2C/`](file:///d:/APEXALL/EmbdeddSystem/Weeks/Week-5-Serial-UART-I2C/) | `week-5-serial-uart-i2c` |
| **Week 6** | Dual-MCU & SPI/CAN | **TBD** (Awaiting) | Dual STM32 Telemetry Cross-Link, Abstract Display Driver (`display_interface.c`), Fast SPI & Automotive CAN Theory | [`Weeks/Week-6-SPI-CAN-DualMCU/`](file:///d:/APEXALL/EmbdeddSystem/Weeks/Week-6-SPI-CAN-DualMCU/) | `week-6-spi-can-dualmcu` |

### Practical Milestone Tasks (Code & Simulation Assignments)
| Task | Target Peripherals | Key Deliverable | Local Directory | Branch |
| :--- | :--- | :--- | :--- | :--- |
| **Task 1: GPIO & LED Driver** | PC13, PA1 (GPIOs) | Modular `led.h/.c` driver, active-low/high alternating blink, Proteus circuit | [`Tasks/Task-1-GPIO-LED/`](file:///d:/APEXALL/EmbdeddSystem/Tasks/Task-1-GPIO-LED/) | `task-1-gpio-led` |
| **Task 2: ADC & Timer PWM** | PA0 (ADC1), PA1 (TIM2 PWM) | Potentiometer sampling mapped to 1 kHz PWM dimming, multi-mode ADC comparison | [`Tasks/Task-2-ADC-PWM/`](file:///d:/APEXALL/EmbdeddSystem/Tasks/Task-2-ADC-PWM/) | `task-2-adc-pwm` |
| **Task 3: Dual-MCU & Display** | 2x STM32, USART1, Screen | Cross-board serial telemetry stream, Abstract display driver, Proteus dual simulation | [`Tasks/Task-3-UART-Display/`](file:///d:/APEXALL/EmbdeddSystem/Tasks/Task-3-UART-Display/) | `task-3-uart-display` |

> [!TIP]
> **Navigation Tip**: All tasks and weekly materials are available **both** as direct folders on the `main` branch (for immediate browsing) and as isolated Git branches (`git checkout <branch-name>`) for branching your work.

---

## Master Spreadsheet Roadmap (`Apex_Embedded_6Week_Plan.xlsx`)

The repository root includes a local planning spreadsheet (**never committed to Git**) containing:
1. **`6_Week_Curriculum`**: High-contrast, screenshot-ready overview formatted with video counts and watch times for team announcement chats.
2. **`Video_Directory`**: Central indexed directory of all 26 curated video links and master course timestamps.
3. **`W1_Daily_Operations` – `W6_Daily_Operations`**: Day-by-day actionable operational guides following the 4-day active rhythm.


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

### 1. Core Prerequisites & Command-Line Tools
* **Git for Windows (with Git Bash)**: [git-scm.com/download/win](https://git-scm.com/download/win) — Git version control and terminal environment (ash).
* **MinGW-w64 (GCC & Make)**: [WinLibs Standalone Build](https://winlibs.com/) or [w64devkit Release](https://github.com/skeeto/w64devkit/releases) — Host GCC and Make toolchain for Week 1 compilation fundamentals.

### 2. Development Environment
* **IDE**: [STM32CubeIDE (v1.14.0 or newer)](https://www.st.com/en/development-tools/stm32cubeide.html) — Primary embedded IDE with integrated rm-none-eabi-gcc toolchain, GDB debugger, and HAL drivers.
* **Firmware Package**: STM32Cube FW_F1 (Firmware package for STM32F1 series).
* **Flashing Utility**: [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) — Firmware flasher and ST-Link firmware updater.

### 3. Simulation Environment
* **Proteus Design Suite**: [Proteus 8.13 SP0 or higher](https://www.labcenter.com/).
* Ensure the **STM32F103C8** model is available in your Proteus library.
* Set the microcontroller properties in Proteus to:
  * **Crystal Frequency**: 8MHz (or 72MHz internal clock matching your RCC settings).
  * **Program File**: Point directly to your compiled .hex output located in Firmware/Debug/.

### 4. Physical Hardware (Optional / Bonus)
* STM32F103C8T6 "Blue Pill" development board.
* ST-Link V2 programmer / debugger.
* Solderless breadboard, jumper wires, potentiometers (10kΩ), resistors (220Ω, 330Ω), and LEDs.

---

## General Engineering Directives

* **No Sprawling `main.c`**: Never dump low-level driver logic directly into `main.c`. Keep `main.c` reserved for state initialization and application loop coordination.
* **Defensive Programming**: Check return statuses of HAL initialization routines.
* **Non-Blocking Architecture**: Avoid blocking `HAL_Delay()` wherever timers or state machines can achieve non-blocking execution.
* **Meaningful Git Commits**: Commit regularly as you pass milestones. Write descriptive commit messages.
