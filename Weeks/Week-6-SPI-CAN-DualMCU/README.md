# Week 6 — High-Speed SPI, Automotive CAN Bus Overview & Dual-MCU System

[![Week](https://img.shields.io/badge/Week-6%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-SPI%20%7C%20CAN%20Bus%20%7C%20Dual--MCU%20System-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--3--uart--display-orange.svg)](#)

Welcome to **Week 6** (Capstone Week) of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives

> [!NOTE]
> **Track Directive**: Protocols **SPI** and **CAN Bus** are introduced with a **fast theoretical foundation**, while the practical hands-on coding focuses on the **Dual-MCU UART Telemetry Bus and Display System**.

1. **High-Speed SPI (Fast Theoretical Foundation)**:
   * 4-wire synchronous communication: Master Out Slave In (`MOSI`), Master In Slave Out (`MISO`), Serial Clock (`SCK`), Chip Select (`CS`/`NSS`).
   * Clock Polarity (`CPOL`) and Clock Phase (`CPHA`) 4-mode timing matrix.
   * Racing application: Interfacing high-speed magnetic angle encoders (AS5047P / AS5048A) for BLDC motor rotor angle tracking.
2. **Automotive CAN Bus (Fast Theoretical Foundation)**:
   * Differential physical layer (`CAN_H` / `CAN_L`) with $120\Omega$ termination for high EMI noise immunity.
   * Multi-master message-based arbitration: Dominant (`0`) overrides Recessive (`1`).
   * Standard 11-bit vs Extended 29-bit CAN identifiers.
   * Why CAN is standard across Formula Student / automotive ECUs, inverters, and battery management systems (BMS).
3. **Dual-MCU Distributed Architecture (Hands-on Coding Focus)**:
   * Node 1 (Transmitter ECU): Gathers simulated telemetry and serializes over USART1.
   * Node 2 (Receiver ECU): Receives packet stream, decodes payload, and updates the modular display interface.
   * Common ground reference rule in single-ended serial links.

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
