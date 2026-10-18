# Week 6 — High-Speed SPI, Automotive CAN Bus Overview & Dual-MCU System

[![Week](https://img.shields.io/badge/Week-6%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-SPI%20%7C%20CAN%20Bus%20%7C%20Dual--MCU%20System-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--3--uart--display-orange.svg)](#)

Welcome to **Week 6** (Capstone Week) of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **SPI (Serial Peripheral Interface)**:
   * High-speed 4-wire synchronous communication (MOSI, MISO, SCK, CS/NSS).
   * Clock Polarity (`CPOL`) and Clock Phase (`CPHA`) 4-mode matrix.
   * Interfacing high-speed vehicle sensors: Magnetic Angle Encoders (e.g. AS5047P / AS5048A) for BLDC rotor position, high-frequency IMUs.
2. **Automotive CAN Bus (Controller Area Network)**:
   * Differential physical layer (`CAN_H` / `CAN_L`) with $120\Omega$ split termination.
   * Multi-master bus arbitration: Dominant (`0`) vs Recessive (`1`) bits, message identifier priority.
   * Standard (11-bit) vs Extended (29-bit) CAN frames.
   * Why CAN is the universal standard for racecar ECUs, motor controllers, and battery management systems (BMS).
3. **Dual-MCU Distributed Architecture (Task 3 Finalization)**:
   * Node 1 (Transmitter / Sensor ECU): Serializes vehicle metrics.
   * Node 2 (Receiver / Dashboard ECU): Deserializes metrics and drives the abstract display layer.
   * Common ground reference necessity in single-ended communication.

---

## Daily Operational Guide

* **Day 1 (Monday)**: Watch video lectures on SPI timing diagrams and CAN Bus differential physical signaling.
* **Day 2 (Tuesday)**: Attend live whiteboard session: analyzing CAN bus arbitration, bit stuffing, and error frames.
* **Day 3 (Wednesday)**: Live coding lab: configuring Dual STM32 nodes in Proteus and connecting TX/RX crossover lines.
* **Day 4 (Thursday)**: Office hours for troubleshooting multi-MCU synchronization and display update jitter.
* **Day 5 (Friday)**: Complete modular display driver abstraction (`display_interface.c` & `display_interface.h`).
* **Day 6 (Saturday)**: Submit Task 3 final PR, complete simulation demo video, and final learning phase report.
* **Day 7 (Sunday)**: Attend Capstone Oral Code Defense Interview and receive final track evaluation.

---

## Associated Milestone Task
Complete the full Task 3 assignment on:
```bash
git checkout task-3-uart-display
```
Refer to the `task-3-uart-display` branch for the multi-MCU codebase, telemetry packets, and Proteus layout.
