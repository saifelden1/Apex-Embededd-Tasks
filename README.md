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

## Daily Operational Guide

* **Day 1 (Monday)**: Watch curated toolchain installation videos and study Cortex-M memory architecture.
* **Day 2 (Tuesday)**: Attend live technical whiteboard session on GPIO internal circuits.
* **Day 3 (Wednesday)**: Replicate live CubeIDE project creation and Proteus simulation setup.
* **Day 4 (Thursday)**: Join office hours for setup debugging and hardware verification.
* **Day 5 (Friday)**: Complete modular driver implementation (`led.c` & `led.h`) and record simulation video.
* **Day 6 (Saturday)**: Submit Task 1 PR and completed `Template_Report.md`.
* **Day 7 (Sunday)**: Attend 1-on-1 oral code defense interview.

---

## Associated Milestone Task
Switch to the official Task 1 branch to complete your code and simulation assignment:
```bash
git checkout task-1-gpio-led
```
Refer to the `task-1-gpio-led` branch `README.md` for the complete API contract, pinout specifications, and reporting guidelines.
