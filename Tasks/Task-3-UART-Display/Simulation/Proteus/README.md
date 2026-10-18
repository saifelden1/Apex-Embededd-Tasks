# Proteus 8 Simulation Guide — Task 3 (Dual STM32 UART & Display)

## 1. Components Required
Pick the following components from the Proteus Library:
* 2x `STM32F103C8` (Microcontrollers: ECU-1 Transmitter, ECU-2 Receiver)
* `VIRTUAL TERMINAL` (Found under **Virtual Instruments Mode** in the left toolbar)
* Display Unit (e.g., `LM016L` for standard 16x2 Alpha-numeric LCD, or a second Virtual Terminal)
* `POWER` and `GROUND` (From Terminals mode)

---

## 2. Wiring Connections

```
      ECU-1 (Transmitter)                         ECU-2 (Receiver)
        [STM32F103C8]                              [STM32F103C8]
       +-------------+                            +-------------+
       |             |                            |             |
       |    PA9 (TX) |------+-------------------->| PA10 (RX)   |
       |             |      |                     |             |
       |         GND |--+   |                     |         GND |--+
       +-------------+  |   |                     +------+------+  |
                        |   |                            |         |
                        |   |     +------------------+   |         |
                        |   +---->| RXD (Pin 2)      |   |         |
                        |         | VIRTUAL TERMINAL |   |         |
                        |         +------------------+   |         |
                        |                                |         |
                        +----------- COMMON GND ---------+---------+
                                                         |
                                                  [ Display Bus ]
                                                         |
                                                         v
                                                 +---------------+
                                                 | Display Unit  |
                                                 +---------------+
```

1. **Serial Interconnection**:
   * Connect `PA9 (USART1_TX)` of ECU-1 to `PA10 (USART1_RX)` of ECU-2.
   * Connect `RXD` pin of the **Virtual Terminal** to the same communication wire (`PA9`/`PA10`) to snoop on the serial stream.
2. **Display Connections (ECU-2)**:
   * Connect the display control/data lines according to your pin assignments (e.g. `PB0-PB5` or `I2C1 PB6/PB7`).

---

## 3. Firmware Loading & Simulation Execution
1. Compile the **Transmitter Node** project to produce `Firmware/Transmitter_Node/Debug/Transmitter.hex`.
2. Compile the **Receiver Node** project to produce `Firmware/Receiver_Node/Debug/Receiver.hex`.
3. In Proteus:
   * Double-click ECU-1 $\rightarrow$ Load `Transmitter.hex`.
   * Double-click ECU-2 $\rightarrow$ Load `Receiver.hex`.
4. Click **Play** to run simulation.
5. In the **Virtual Terminal window**:
   * Observe regular packet arrivals (header `0xAA`, payload, checksum, end `0x55`).
6. On the **Display Unit**:
   * Observe formatted speed, voltage, and telemetry metrics updating smoothly.
