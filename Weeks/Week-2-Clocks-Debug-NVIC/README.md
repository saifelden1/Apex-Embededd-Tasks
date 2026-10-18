# Week 2 — Clock Tree (RCC), In-Circuit Debugging & Interrupts (NVIC/EXTI)

[![Week](https://img.shields.io/badge/Week-2%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-Clock%20Tree%20%7C%20SWD%20Debug%20%7C%20NVIC%2FEXTI-brightgreen.svg)](#)

Welcome to **Week 2** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **STM32 Clock Architecture (RCC)**:
   * Internal High Speed (HSI @ 8MHz) vs External High Speed (HSE @ 8MHz crystal).
   * Phase-Locked Loop (PLL) configuration to reach maximum 72 MHz SYSCLK.
   * Bus division: AHB prescaler (72MHz), APB1 low-speed peripheral bus (max 36MHz), APB2 high-speed peripheral bus (max 72MHz).
2. **In-Circuit Debugging Techniques (SWD)**:
   * Serial Wire Debug (SWCLK & SWDIO pins).
   * Hardware breakpoints, watchpoints, live variable tracking.
   * Special Function Register (SFR) view and Memory Browser.
   * Debugging **HardFaults**: Inspecting the Link Register (LR), Program Counter (PC), and Fault Status Registers (`CFSR`, `HFSR`).
3. **Interrupts & Nested Vectored Interrupt Controller (NVIC)**:
   * Preemption Priority vs Sub-priority grouping.
   * Interrupt Service Routine (ISR) latency and re-entrancy rules.
   * External Interrupts (EXTI): Triggering events on rising/falling edge.
   * Software and hardware button debouncing state machines.

---

## Daily Operational Guide

* **Day 1 (Monday)**: Watch curated lectures on STM32 RCC clock tree and NVIC priority registers.
* **Day 2 (Tuesday)**: Attend live whiteboard session: analyzing HardFault exceptions and stack dump unwinding.
* **Day 3 (Wednesday)**: Live coding lab: configuring EXTI push button on PB0 to trigger non-blocking LED toggle.
* **Day 4 (Thursday)**: Office hours for debugging clock frequency mismatch and Proteus crystal settings.
* **Day 5 (Friday)**: Practice SWD breakpoint stepping and inspect memory registers during active interrupts.
* **Day 6 (Saturday)**: Submit Week 2 Lab Report documenting clock calculations and EXTI state machine code.
* **Day 7 (Sunday)**: Attend 1-on-1 oral defense review.

---

## Key Formula for Clock Verification
$$\text{SYSCLK} = \frac{\text{HSE}}{\text{PREDIV}} \times \text{PLLMUL} = \frac{8\text{ MHz}}{1} \times 9 = 72\text{ MHz}$$
$$\text{APB1 Clock} = \frac{\text{SYSCLK}}{\text{APB1\_DIV}} = \frac{72\text{ MHz}}{2} = 36\text{ MHz}$$
