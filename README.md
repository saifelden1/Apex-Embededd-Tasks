# Week 5 — Serial Communication: UART & I2C Bus Protocols

[![Week](https://img.shields.io/badge/Week-5%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-UART%20%7C%20Ring%20Buffers%20%7C%20I2C%20Bus-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--3--uart--display-orange.svg)](#)

Welcome to **Week 5** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **UART / USART Serial Architecture**:
   * Asynchronous framing: Start bit, 8 data bits, parity, stop bits (8N1).
   * Baud rate generation: Clock divider registers (`USART_BRR`), fractional baud rates, and error rate tolerance.
   * Interrupt-driven reception (`HAL_UART_Receive_IT`) and ring buffer implementation to prevent buffer overflow.
2. **Telemetry Packet Serialization**:
   * Framing protocols: Defining clear packet boundaries (`START = 0xAA`, `END = 0x55`).
   * Integrity checks: XOR checksum calculation and detection of corrupt transmissions.
   * Multi-byte data packaging: Big-endian vs Little-endian packing for speed, voltage, and state flags.
3. **I2C Bus Protocol Fundamentals**:
   * Synchronous 2-wire serial interface: Serial Clock (`SCL`) and Serial Data (`SDA`).
   * Open-Drain electrical bus with external pull-up resistors ($2.2\text{ k}\Omega - 4.7\text{ k}\Omega$).
   * Protocol states: START condition, 7-bit Device Address + R/W bit, ACK/NACK, data bytes, STOP condition.
   * Application: Interfacing digital sensors (IMUs, temperature sensors, EEPROMs, I2C LCDs).

---

## Daily Operational Guide

* **Day 1 (Monday)**: Watch video lectures on asynchronous UART timing vs synchronous I2C transactions.
* **Day 2 (Tuesday)**: Attend live whiteboard session: designing a non-blocking serial packet parser state machine.
* **Day 3 (Wednesday)**: Live coding lab: configuring USART1 at 115200 bps and inspecting bytes in the Proteus Virtual Terminal.
* **Day 4 (Thursday)**: Office hours for debugging framing errors, baudrate clock mismatches, and missed bytes.
* **Day 5 (Friday)**: Complete modular packet driver (`uart_comm.c` & `uart_comm.h`) and test checksum verification.
* **Day 6 (Saturday)**: Submit Week 5 packet driver lab report and Proteus Virtual Terminal traces.
* **Day 7 (Sunday)**: Attend 1-on-1 oral defense review.

---

## Associated Milestone Task
This week prepares you for the communication half of Task 3. Switch to:
```bash
git checkout task-3-uart-display
```
Refer to the `task-3-uart-display` branch for full telemetry packet definitions and cross-MCU wiring.
