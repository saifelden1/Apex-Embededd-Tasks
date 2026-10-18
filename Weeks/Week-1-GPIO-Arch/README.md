# Week 1 — Architecture, Toolchain, Git/AI Workflow & GPIO Driver

[![Week](https://img.shields.io/badge/Week-1%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-ARM%20Cortex--M3%20%7C%20GPIO%20%7C%20Git-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--1--gpio--led-orange.svg)](#)

Welcome to **Week 1** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **Understand ARM Cortex-M Architecture**: Core registers (R0-R15), Program Counter (PC), Link Register (LR), Stack Pointer (MSP/PSP), memory map (Flash vs SRAM).
2. **Environment Setup**: Install and configure STM32CubeIDE, ST-Link V2 drivers, and Proteus 8.13 simulation.
3. **Git & AI Engineering Directives**:
   * Master branch creation, commits, PR workflows.
   * Understand the **AI Usage Policy**: AI tools are allowed for guidance, but you must pass an **oral line-by-line defense interview**.
4. **GPIO Physical Layer**:
   * Push-Pull vs Open-Drain MOSFET structures.
   * Pull-Up / Pull-Down resistor configurations.
   * Slew rate / speed settings and their effect on EMI.
   * Bit Set/Reset Register (`BSRR` / `BRR`) vs Output Data Register (`ODR`).

---

## Daily Operational Guide & Curated Video Links

* **Day 1 (Monday) — Git & Toolchain Setup**:
  * 📺 [Git & GitHub Tutorial](https://www.youtube.com/watch?v=mAFoROnOfHs)
  * Install STM32CubeIDE & Proteus 8.13. Clone repository and verify local environment.
* **Day 2 (Tuesday) — Memory Map & Bus System**:
  * 📺 [ARM Cortex-M Memory Map](https://www.youtube.com/watch?v=hyIEUCIVhQQ&t=895s)
  * 📺 [Bus Interface (AHB / APB)](https://www.youtube.com/watch?v=jTASGW8HEa0&list=PLoiqjtgvXf9e2VJk8GWEXwECPM_7JRwkE&index=9)
  * Understand Flash (`0x08000000`), SRAM (`0x20000000`), and peripheral bus routing.
* **Day 3 (Wednesday) — CubeIDE Project, Debug & Blink**:
  * 📺 [Debug and Blink (First 30 min only)](https://www.youtube.com/watch?v=LIJ_G-LU_Qg&list=PLfIJKC1ud8ghW6bJq2lN-cAuElyF4hpvR)
  * Create project for `STM32F103C8`, configure PC13 & PA1, build project and verify `.hex` generation.
* **Day 4 (Thursday) — Simple Driver Design & Live Q&A**:
  * 30-45 min drop-in session: writing simple helper functions in `led.h` & `led.c` (Init, On, Off, Toggle).
  * Address why PC13 onboard LED is active-low (0 is ON, 1 is OFF).
* **Day 5 (Friday) — Simulation Lab**:
  * Build circuit in Proteus (STM32F103 + Resistor + LED). Load `.hex` file and record a 10-second demo video of alternating blinking.
* **Day 6 (Saturday) — Submission Deadline**:
  * Submit PR link or files, demo video, and completed `Template_Report.md` by 11:59 PM.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute conversational check-in: explain your code line-by-line and demonstrate understanding.


---

## Associated Milestone Task
Switch to the official Task 1 branch to complete your code and simulation assignment:
```bash
git checkout task-1-gpio-led
```
Refer to the `task-1-gpio-led` branch `README.md` for the complete API contract, pinout specifications, and reporting guidelines.
