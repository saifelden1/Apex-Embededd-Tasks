# Task 3 — Dual-STM32 Inter-Board UART Communication & Display Interface

[![Target](https://img.shields.io/badge/Target-2x%20STM32F103C8T6-blue.svg)](#)
[![Protocol](https://img.shields.io/badge/Protocol-UART%20%2F%20USART-brightgreen.svg)](#)
[![Peripherals](https://img.shields.io/badge/Peripherals-USART1%20%7C%20Display%20Interface-orange.svg)](#)

---

## Objective
In racing vehicle architecture, modern Electronic Control Units (ECUs) do not operate in isolation. Multiple microcontrollers communicate across onboard serial buses (UART, CAN, LIN) to exchange telemetry, state variables, and dashboard alerts.

The goal of this task is to configure a **Dual-STM32 Distributed System**:
1. **Transmitter Node (ECU-1 / Sensor Node)**: Gathers simulated telemetry parameters (Speed, Battery Voltage, Lap Count, Status Flag), packages them into a robust serialized data packet, and transmits over **USART**.
2. **Receiver Node (ECU-2 / Telemetry Dashboard Node)**: Receives the serialized data packet, parses and validates the frame, and formats the real-time telemetry onto a **Screen / Display interface**.
3. **Modular Driver Abstraction**:
   * Implement modular serial packet communication drivers (`uart_comm.h/.c`).
   * Implement a hardware-independent display driver layer (`display_interface.h/.c`), allowing the display hardware (16x2 Parallel LCD, I2C Display, OLED, or Proteus Virtual Terminal) to be swapped without changing core business logic.

---

## System Architecture & Pin Mapping

```
      +--------------------+                      +--------------------+
      |   ECU-1 (Sender)   |                      |  ECU-2 (Receiver)  |
      |   [STM32F103C8]    |                      |   [STM32F103C8]    |
      |                    |                      |                    |
      |       PA9 (USART_TX)--------------------->| PA10 (USART_RX)    |
      |                    |                      |                    |
      |                GND |----------------------| GND (Common Ground)|
      +--------------------+                      +---------+----------+
                                                            |
                                                            | [Display Bus]
                                                            v
                                                  +--------------------+
                                                  |  Display / Screen  |
                                                  +--------------------+
```

### Pin Mapping Table
| Node | Function | MCU Pin | Connected To |
| :--- | :--- | :--- | :--- |
| **ECU-1 (Transmitter)** | `USART1_TX` | `PA9` | ECU-2 `PA10` (`USART1_RX`) |
| **ECU-1 (Transmitter)** | Ground | `GND` | ECU-2 `GND` (Mandatory common reference) |
| **ECU-2 (Receiver)** | `USART1_RX` | `PA10` | ECU-1 `PA9` (`USART1_TX`) |
| **ECU-2 (Receiver)** | Display Interface | Configurable | Screen Data/Control Bus |

---

## Telemetry Packet Protocol Specification

To prevent data corruption, framing errors, or partial reads, data transmitted over the serial link must adhere to a structured packet format:

```
+------------+-------------+----------------+----------------+-----------+----------+
| START BYTE | PACKET ID   | SPEED (km/h)   | VOLTAGE (mV)   | CHECKSUM  | END BYTE |
|   (0xAA)   |   (1 Byte)  |   (2 Bytes)    |   (2 Bytes)    |  (1 Byte) |  (0x55)  |
+------------+-------------+----------------+----------------+-----------+----------+
```

* **Start Delimiter**: `0xAA` (Identifies beginning of valid frame).
* **Packet ID**: Incremental counter ($0 - 255$) to detect lost frames.
* **Payload**:
  * `Speed`: Unsigned 16-bit integer ($0 - 300\text{ km/h}$).
  * `Battery Voltage`: Unsigned 16-bit integer ($9000 - 14000\text{ mV} \rightarrow 9.0\text{V} - 14.0\text{V}$).
* **Checksum**: Simple XOR or 8-bit sum of payload bytes to guarantee data integrity.
* **End Delimiter**: `0x55` (Signifies end of frame).

---

## Technical Milestones

### Milestone 1: USART Peripheral Configuration
* **Baud Rate**: `115200 bps` (standard for automotive debug telemetry).
* **Word Length**: 8 Bits.
* **Stop Bits**: 1 Stop Bit.
* **Parity**: None (8N1).
* **Mode**:
  * ECU-1: Asynchronous Transmit Only (or TX/RX).
  * ECU-2: Asynchronous Receive Only (or TX/RX), enabled with **Interrupt** (`HAL_UART_Receive_IT`) or **DMA with Idle Line Detection**.

### Milestone 2: Modular UART Packet Driver (`uart_comm.h` & `uart_comm.c`)
Create a modular communication driver:
* Serializes telemetry structure into the byte array frame.
* Parses received byte streams and handles packet validation via state-machine decoding (`WAIT_START`, `READ_PAYLOAD`, `VERIFY_CHECKSUM`).

### Milestone 3: Modular Display Abstraction (`display_interface.h` & `display_interface.c`)
Structure the display driver so that application code only invokes abstract functions:
```c
void Display_Init(void);
void Display_Clear(void);
void Display_SetCursor(uint8_t row, uint8_t col);
void Display_PrintString(const char *str);
void Display_PrintTelemetry(uint16_t speed, float voltage);
```
*(The underlying implementation can target Proteus Character LCD, I2C backpack, or Virtual Terminal).*

### Milestone 4: Proteus Simulation & Verification
1. Place two `STM32F103C8` instances in Proteus 8.
2. Wire `PA9` of Node 1 directly to `PA10` of Node 2.
3. Attach a **Virtual Terminal** to the communication line to observe raw ASCII / hex frames in real time.
4. Connect the display to Node 2 and compile both firmware images (`Transmitter.hex` and `Receiver.hex`).
5. Verify dynamic updating of received numbers on the display.

---

## Oral Code Defense Preparation (Interview Topics)

1. **Common Ground Necessity**: Why must the grounds of two physical microcontrollers be tied together in single-ended UART communication? What happens if they are not?
2. **Buffer Overrun & Ring Buffers**: What happens if ECU-1 sends packets faster than ECU-2 can update its screen? How does a circular ring buffer or DMA prevent dropped bytes?
3. **Framing & Parity**: What causes a UART framing error? How does the start and stop bit mechanism ensure clock synchronization between independent crystal oscillators?
4. **Packet Synchronization**: Why is a delimiter byte (`0xAA`) or checksum essential when transmitting multi-byte binary structures?

---

## Required Deliverables

1. **Source Code**:
   * `Firmware/Transmitter_Node/`: CubeIDE project for ECU-1.
   * `Firmware/Receiver_Node/`: CubeIDE project for ECU-2 including `display_interface` and `uart_comm` drivers.
2. **Simulation / Hardware Media**:
   * Proteus screenshot showing both microcontrollers communicating and the display updating.
   * Video demo showing dynamic packet reception and telemetry refresh.
3. **Task Documentation Report**:
   * Completed [`Template_Report.md`](Template_Report.md) documenting packet structure, baudrate calculations, state machine design, and debugging hurdles.
