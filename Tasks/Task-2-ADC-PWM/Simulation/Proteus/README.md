# Proteus 8 Simulation Guide — Task 2 (ADC & Timer PWM)

## 1. Components Required
Pick the following components from the Proteus Library (`P` shortcut):
* `STM32F103C8` (Microcontroller)
* `POT-HG` (Interactive Potentiometer with clickable up/down arrows)
* `LED-RED` or `LED-BLUE` (Active Animated LED)
* `RES` (Resistor, set value to `330R`)
* `OSCILLOSCOPE` (Found under **Virtual Instruments Mode** in the left toolbar)
* `POWER` and `GROUND` (From Terminals mode)

---

## 2. Circuit Wiring Diagram

```
                 +3.3V (POWER)
                   |
                +-----+
                |     |
                | POT |<-- Slider Wiper Pin ----> PA0 (ADC1_IN0)
                |     |
                +-----+
                   |
                  GND

              STM32F103C8
           +---------------+
           |               |
           |           PA0 |<--- [ Potentiometer Wiper ]
           |               |
           |           PA1 |----+---> [ 330R Resistor ] --->|--- GND (LED)
           |   (TIM2_CH2)  |    |
           +---------------+    +---> Channel A of OSCILLOSCOPE
```

1. **Potentiometer Wiring**:
   * Terminal 1 $\rightarrow$ `+3.3V` (POWER terminal).
   * Terminal 2 $\rightarrow$ `PA0` (MCU ADC1 Channel 0).
   * Terminal 3 $\rightarrow$ `GROUND`.
2. **PWM LED & Oscilloscope Wiring**:
   * Connect `PA1` of `STM32F103C8` to:
     * One end of a `330R` resistor (the other end goes to the LED Anode, with LED Cathode to GND).
     * Input **Channel A** of the Virtual **OSCILLOSCOPE**.
   * Connect Ground of the oscilloscope to circuit ground.

---

## 3. Running & Testing the Simulation
1. Compile your STM32CubeIDE project to generate `Firmware/Debug/Firmware.hex`.
2. Double-click the `STM32F103C8` component in Proteus:
   * Select `Program File` $\rightarrow$ `Firmware/Debug/Firmware.hex`.
   * Set `Crystal Frequency` $\rightarrow$ `8.000000MHz` (or matching clock).
3. Click the **Play** button to start the simulation.
4. During simulation:
   * Click the potentiometer arrows (`+` and `-`) to vary the analog voltage from 0% to 100%.
   * In the **Oscilloscope window**, observe the pulse width expanding from 0% (constant LOW) to 100% (constant HIGH).
   * Observe the visual intensity of the LED changing accordingly.
