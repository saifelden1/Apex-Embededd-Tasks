# Task 1 — STM32F103C8T6 GPIO Configuration & Modular LED Driver

[![Target](https://img.shields.io/badge/Target-STM32F103C8T6%20(Blue%20Pill)-blue.svg)](#)
[![Peripheral](https://img.shields.io/badge/Peripheral-GPIO-brightgreen.svg)](#)
[![Simulation](https://img.shields.io/badge/Simulation-Proteus%208-orange.svg)](#)

---

## Objective
The goal of this task is to configure the **STM32F103C8T6 (Blue Pill)** using **STM32CubeIDE**, establish a clean clock configuration, drive both onboard and external LEDs, and encapsulate all hardware-level manipulations into a professional, modular **Board Support Package (BSP)** driver (`led.h` / `led.c`).

You must verify your implementation via **Proteus 8 simulation** (or physical hardware) and document your steps, bugs, and technical learnings.

---

## Hardware Specifications & Pin Mapping

| Peripheral | MCU Pin | Electrical Configuration | Logic Behavior |
| :--- | :--- | :--- | :--- |
| **Onboard User LED** | `PC13` | Open-Drain / Push-Pull output | **Active-LOW** (`0` = ON, `1` = OFF) |
| **External Red LED** | `PA1` | Push-Pull output with 330Ω resistor to GND | **Active-HIGH** (`1` = ON, `0` = OFF) |

> [!NOTE]
> On standard Blue Pill boards, the `PC13` LED cathode is connected to the MCU pin, while the anode is tied to `+3.3V` through a resistor. Driving the pin `LOW` turns the LED on. Your modular driver must handle both **Active-High** and **Active-Low** configurations cleanly without hardcoding inverted logic in `main.c`.

---

## Technical Milestones

### Milestone 1: Clock & GPIO Configuration in STM32CubeIDE
1. Create a new STM32 project targeting `STM32F103C8Tx`.
2. Configure RCC: High Speed Clock (HSE) to Crystal/Ceramic Resonator (or HSI if simulating with internal oscillator).
3. Set SYSCLK to 72 MHz (HSE + PLL) or 8 MHz.
4. Pinout setup:
   * Configure `PC13` as `GPIO_Output` (Label: `LED_ONBOARD`).
   * Configure `PA1` as `GPIO_Output` (Label: `LED_EXTERNAL`).
   * Output speed: `GPIO_SPEED_FREQ_LOW` (or `MEDIUM`).
5. Enable **Generate HEX file** in CubeIDE (`Project Properties -> C/C++ Build -> Settings -> Tool Settings -> MCU Post build outputs -> Convert to Intel Hex file`).

### Milestone 2: Modular Driver Architecture (`led.h` & `led.c`)
Create a modular driver inside `Firmware/Drivers/BSP/LED/` with clean separation of concerns:
* `led.h`: Defines structures, configuration enums, and public APIs.
* `led.c`: Implements initialization, toggling, and explicit state setting using HAL/Register calls.

#### Required API Specification:
```c
typedef enum {
    LED_ACTIVE_LOW  = 0,
    LED_ACTIVE_HIGH = 1
} LED_ActiveState_t;

typedef enum {
    LED_STATE_OFF = 0,
    LED_STATE_ON  = 1
} LED_State_t;

typedef struct {
    GPIO_TypeDef       *port;
    uint16_t           pin;
    LED_ActiveState_t  active_level;
    LED_State_t        current_state;
} LED_Handle_t;

void LED_Init(LED_Handle_t *hled, GPIO_TypeDef *port, uint16_t pin, LED_ActiveState_t active_level);
void LED_SetState(LED_Handle_t *hled, LED_State_t state);
void LED_On(LED_Handle_t *hled);
void LED_Off(LED_Handle_t *hled);
void LED_Toggle(LED_Handle_t *hled);
```

### Milestone 3: Application Logic in `main.c`
In `Core/Src/main.c`, initialize both LEDs using the handles and create a blinking sequence:
* Synchronous toggle: Alternate blinking between the on-board LED and external LED every 500ms.
* Keep `main.c` free of raw `HAL_GPIO_WritePin` calls for the LEDs — use your `LED_*` BSP functions.

### Milestone 4: Proteus Simulation & Verification
1. Open or build the circuit in Proteus 8 (refer to [`Simulation/Proteus/README.md`](Simulation/Proteus/README.md)).
2. Connect `STM32F103C8` with an external LED on `PA1` (via 330Ω resistor) and probe `PC13`.
3. Load the compiled `.hex` file into the STM32 model properties.
4. Run the interactive simulation and record evidence.

---

## Oral Code Defense Preparation (Interview Topics)

During the technical review, you will be asked to explain and defend every line of code submitted. Be prepared to answer:
1. **Underlying Registers**: What registers does `HAL_GPIO_WritePin` modify? (Explain `BSRR` vs `BRR` vs `ODR`).
2. **Push-Pull vs Open-Drain**: What is the physical MOSFET structure inside the MCU pin for Push-Pull vs Open-Drain? Why is Open-Drain needed for I2C or shared buses?
3. **GPIO Speed**: What does setting the GPIO speed to `Low (2MHz)`, `Medium (10MHz)`, or `High (50MHz)` physically change on the chip? What are the tradeoffs (EMI, slew rate, power consumption)?
4. **Active Logic**: How does your driver abstract active-high and active-low so the user of the driver doesn't need to care?

---

## Required Deliverables

Submit the following items:
1. **Source Code**:
   * Complete `Firmware/` folder containing your `.ioc`, `Core/`, and `Drivers/BSP/LED/` files.
2. **Simulation / Hardware Media**:
   * Screenshots of the schematic in Proteus with logic probes indicating voltage levels.
   * Short video/GIF showing the alternating blinking behavior in real-time.
3. **Task Documentation Report**:
   * Completed [`Template_Report.md`](Template_Report.md) filled with your step-by-step process, challenges, and debugging log.
