# Proteus 8 Simulation Guide — Task 1 (GPIO & LED)

## 1. Components Required
Pick the following components from the Proteus Library (`P` shortcut):
* `STM32F103C8` (Microcontroller)
* `LED-RED` (Active Animated LED)
* `RES` (Resistor, set value to `330R`)
* `GROUND` (From Terminals mode)
* `POWER` (From Terminals mode, `+3.3V` / `+5V`)

---

## 2. Circuit Schematic Connections

```
              STM32F103C8
           +---------------+
           |               |
           |          PC13 |----[ Resistor 1k ]----[|<--- +3.3V (On-board Active-Low simulation)
           |               |
           |           PA1 |----[ Resistor 330R ]--->|---- GND (External Active-High)
           |               |
           +---------------+
```

1. **External LED (`PA1`)**:
   * Connect `PA1` of `STM32F103C8` to pin 1 of the `330R` resistor.
   * Connect pin 2 of the resistor to the Anode (triangle side) of `LED-RED`.
   * Connect the Cathode (flat bar side) of `LED-RED` to `GROUND`.
2. **On-board LED Probe (`PC13`)**:
   * To simulate the onboard PC13 LED in Proteus:
     * Connect Anode of `LED-RED` to `+3.3V` (POWER terminal).
     * Connect Cathode of `LED-RED` to `PC13` through a `1k` resistor.
     * When `PC13` is LOW (`0V`), the LED illuminates.

---

## 3. Loading the Firmware (.hex) into Proteus
1. Build your project in STM32CubeIDE in **Debug** or **Release** mode.
2. Verify that the `.hex` file is generated inside `Firmware/Debug/Firmware.hex`.
3. In Proteus, **Double-Click** on the `STM32F103C8` component to open Edit Component properties:
   * **Program File**: Browse to `Firmware/Debug/Firmware.hex`.
   * **Crystal Frequency**: Set to `8.000000MHz` (or your PLL clock speed).
4. Click **OK**.
5. Press the **Play / Run Simulation** button (bottom left of Proteus).
6. Observe both LEDs blinking alternately.
