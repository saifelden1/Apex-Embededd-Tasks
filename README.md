# Week 2 — Cortex-M3 Architecture, GPIO Circuitry & Debugging

[![Week](https://img.shields.io/badge/Week-2%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-Memory%20Map%20%7C%20GPIO%20%7C%20Debugging-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--1--gpio--led-orange.svg)](#)

Welcome to **Week 2** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **ARM Cortex-M3 Memory Map & Bus Matrix**:
   * 4GB address space: Flash (`0x08000000`), SRAM (`0x20000000`), Peripherals (`0x40000000`).
   * Bus Matrix: AHB (72 MHz), APB1 (36 MHz), APB2 (72 MHz) peripheral routing.
2. **GPIO Circuitry Deep-Dive**:
   * Push-Pull vs Open-Drain MOSFET structures.
   * Internal Pull-Up and Pull-Down resistors.
   * Why the onboard PC13 LED is **Active-Low** (Logic 0 = ON, Logic 1 = OFF).
   * Bit Set/Reset Register (`BSRR`/`BRR`) vs Output Data Register (`ODR`).
3. **In-Circuit Debugging (SWD)**:
   * Setting hardware breakpoints in STM32CubeIDE.
   * Stepping through code: Step Over (`F6`), Step Into (`F5`), Step Return (`F7`).
   * Watching variables and inspecting Special Function Registers (SFRs) in real time.
4. **Digital Input & Output**:
   * Polling push-button input on `PA0` with internal pull-up using `HAL_GPIO_ReadPin()`.
   * Driving LEDs on `PC13` and `PA1`.

---

## Daily Operational Guide & Curated Links

* **Day 1 (Monday) — Memory Map & Bus System**:
  * 📺 [ARM Cortex-M Memory Map](https://www.youtube.com/watch?v=hyIEUCIVhQQ&t=895s)
  * 📺 [Bus Interface (AHB / APB)](https://www.youtube.com/watch?v=jTASGW8HEa0)
  * Understand Flash, SRAM, and GPIO peripheral base addresses.
* **Day 2 (Tuesday) — GPIO Circuitry & Active-Low**:
  * Push-Pull vs Open-Drain; why PC13 is active-low.
  * Search: `STM32 GPIO push pull vs open drain active low`.
* **Day 3 (Wednesday) — Live Session: CubeIDE Setup & Debugging**:
  * 45-min live session: creating project for `STM32F103C8`, setting clocks, generating `.hex`.
  * 📺 [Debug and Blink (First 30 min)](https://www.youtube.com/watch?v=LIJ_G-LU_Qg)
  * 📺 [Master Course: GPIO Control](https://www.youtube.com/watch?v=vKyL43qXPpk&t=2974s)
* **Day 4 (Thursday) — Button Input & Driver Coding**:
  * 📺 [Master Course: Button Reading](https://www.youtube.com/watch?v=vKyL43qXPpk&t=4478s)
  * Implement modular `led.h` and `led.c` helper driver; read button on `PA0`.
* **Day 5 (Friday) — Offline Workshop Day**:
  * Meet at workshop: assemble circuit in Proteus 8.13 (STM32 + LED + Button).
  * Load `.hex` file and test button toggling LED in simulation.
* **Day 6 (Saturday) — Milestone Task 1 Submission**:
  * Submit Task 1 deliverable: modular code + Proteus demo video + report by 11:59 PM.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute check-in: explain why PC13 is active-low, how SWD breakpoints work, and walk through code line-by-line.

---

## Associated Milestone Task
Switch to the official Task 1 branch:
```bash
git checkout task-1-gpio-led
```
Refer to [`Tasks/Task-1-GPIO-LED/README.md`](../../Tasks/Task-1-GPIO-LED/README.md) for full circuit specifications.
