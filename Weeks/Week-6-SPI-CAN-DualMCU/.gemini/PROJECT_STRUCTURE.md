# Apex Racing Team — Embedded Systems Onboarding Repository Structure

## Overview
This repository contains the training tracks and tasks for the Apex Racing Team embedded systems division.
The repository is organized into a primary branch (`main`) and three dedicated task branches.

## Branch Map
* `main`: Repository documentation, environment guidelines, track roadmap, AI policy, and submission instructions.
* `task-1-gpio-led`: Task 1 — STM32F103C8T6 GPIO configuration & modular LED driver.
* `task-2-adc-pwm`: Task 2 — Potentiometer analog read via ADC & LED dimming via Timer PWM (with ADC modes bonus).
* `task-3-uart-display`: Task 3 — Dual STM32 inter-board UART communication and display interface.

## Directory Layout (Per Task Branch)
```
Apex-Tasks/
├── .gemini/
│   └── PROJECT_STRUCTURE.md     # Repo mapping and AI context
├── Firmware/                    # STM32CubeIDE project root
│   ├── Core/                    # Application logic (main.c, stm32f1xx_it.c)
│   └── Drivers/
│       └── BSP/                 # Board Support Package modular drivers (.c / .h)
├── Simulation/
│   └── Proteus/                 # Proteus 8 schematic & simulation guide
├── Template_Report.md           # Submission documentation template
└── README.md                    # Detailed task guide, specs, and requirements
```
