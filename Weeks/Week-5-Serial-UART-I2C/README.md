# Week 5 — Serial Communication: UART & I2C Bus Protocols

[![Week](https://img.shields.io/badge/Week-5%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-UART%20%7C%20Ring%20Buffers%20%7C%20I2C%20Bus-brightgreen.svg)](#)
[![Task](https://img.shields.io/badge/Task-task--3--uart--display-orange.svg)](#)

Welcome to **Week 5** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives

> [!NOTE]
> **Track Directive**: Serial communication is structured into a **fast theoretical foundation for I2C**, paired with a **deep-dive hands-on coding focus on UART**.

1. **UART / USART Deep-Dive Coding**:
   * Asynchronous framing: Start bit, 8 data bits, parity, stop bits (8N1).
   * Baud rate generation: Clock divider registers (`USART_BRR`), fractional baud rates, and error rate tolerance.
   * Interrupt-driven reception (`HAL_UART_Receive_IT`) and ring buffer implementation to prevent buffer overflow.
   * Telemetry Packet Serialization: Framing markers (`0xAA` / `0x55`), XOR checksum calculation, and binary structure packing.
2. **I2C Bus Protocol (Fast Theoretical Foundation)**:
   * Synchronous 2-wire serial interface: Serial Clock (`SCL`) and Serial Data (`SDA`).
   * Open-Drain electrical bus topology with external pull-up resistors ($2.2\text{ k}\Omega - 4.7\text{ k}\Omega$).
   * Protocol transaction sequence: START condition, 7-bit Device Address + R/W bit, ACK/NACK, data payload, STOP condition.
   * Automotive & Sensor context: When to choose I2C vs UART/SPI for onboard sensors.

---


## Daily Operational Guide & Curated Video Links

* **Day 1 (Monday) — Serial Protocols Overview & UART Basics (Parts 1-2)**:
  * 📺 [Communication Protocols Overview](https://www.youtube.com/watch?v=IyGwvGzrqp8)
  * 📺 [UART Code Part 1](https://www.youtube.com/watch?v=KdXSRyPCYuM&list=PLfIJKC1ud8gjmw-l5eDYfzzX5JI19lwhx&index=2)
  * 📺 [UART Code Part 2](https://www.youtube.com/watch?v=JaMwNT0m3Sw&list=PLfIJKC1ud8gjmw-l5eDYfzzX5JI19lwhx&index=3)
  * Understand Simplex vs Half/Full Duplex, asynchronous framing (8N1), baud rate timing, and polling transmission via `HAL_UART_Transmit()`.
* **Day 2 (Tuesday) — UART Non-Blocking Reception & Interrupts (Parts 3-4)**:
  * 📺 [UART Code Part 3](https://www.youtube.com/watch?v=U-NmsOgNB8c&list=PLfIJKC1ud8gjmw-l5eDYfzzX5JI19lwhx&index=4)
  * 📺 [UART Code Part 4](https://www.youtube.com/watch?v=RpDOHqoVNTs&list=PLfIJKC1ud8gjmw-l5eDYfzzX5JI19lwhx&index=5)
  * Non-blocking reception (`HAL_UART_Receive_IT`), callback handling (`HAL_UART_RxCpltCallback`), and ring buffer logic to prevent dropped bytes.
* **Day 3 (Wednesday) — Live Session: Telemetry Packet Framing & State Machine**:
  * 45-min live session: Telemetry packet serialization, binary frame markers (`0xAA` start, `0x55` end), XOR checksum calculation.
  * Code walkthrough: implementing `uart_comm.c` and `uart_comm.h` helper driver.
  * Follow live demo; configure USART1 at 115200 bps in CubeIDE and build with 0 errors.
* **Day 4 (Thursday) — Fast Theoretical I2C Bus & Waveforms**:
  * 📺 [I2C Concept Part 1](https://www.youtube.com/watch?v=_fgWQ3TIhyE)
  * 📺 [I2C Concept Part 2](https://www.youtube.com/watch?v=CAvawEcxoPU&t=14s)
  * 📺 [I2C in Code (Optional Reference)](https://www.youtube.com/watch?v=usvAIEdp_I8)
  * Fast theory: 2-wire synchronous bus (SCL/SDA), open-drain topology with pull-up resistors, START/STOP conditions, ACK/NACK, and 7-bit addressing.
* **Day 5 (Friday) — Offline Lab Day**:
  * In-person meeting at team workshop: connect Proteus Virtual Terminal to PA9 (TX) and PA10 (RX).
  * Inspect packet stream, verify non-blocking reception, and test checksum validation in person.
* **Day 6 (Saturday) — Week 5 Deliverable Submission**:
  * Submit Week 5 packet driver package: code (`uart_comm.c` / `.h`) + Proteus Virtual Terminal traces + report by 11:59 PM.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute check-in: explain how UART synchronizes without a clock line, why XOR checksums are needed in racing telemetry, and why I2C requires open-drain pull-ups.

---

## Associated Milestone Task
This week prepares you for the communication half of Task 3. Switch to:
```bash
git checkout task-3-uart-display
```
Refer to the `task-3-uart-display` branch for full telemetry packet definitions and cross-MCU wiring.
