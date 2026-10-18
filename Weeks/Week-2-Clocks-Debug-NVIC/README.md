# Week 2 — Build Pipeline (.ld, .map, .elf), Memory Sections & Stack vs Heap

[![Week](https://img.shields.io/badge/Week-2%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-Build%20Pipeline%20%7C%20Memory%20Sections%20%7C%20Stack%20vs%20Heap-brightgreen.svg)](#)

Welcome to **Week 2** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **The C Build Pipeline**:
   * **Preprocessing (`gcc -E`)**: Expands `#include`, evaluates `#define` macros, handles `#ifdef` conditional compilation.
   * **Compiling (`gcc -S`)**: Translates high-level C code into Cortex-M assembly instructions.
   * **Assembling (`as`)**: Converts assembly text into machine-code relocatable object files (`.o`).
   * **Linking (`ld`)**: Combines object files with runtime libraries using the Linker Script (`.ld`), resolving symbol addresses.
2. **Output Build Artifacts**:
   * `.elf` (Executable and Linkable Format): Contains binary code, debug symbols, and section headers.
   * `.hex` & `.bin`: Raw binary images flashed to the STM32 Flash memory.
   * `.map` file: Detailed blueprint showing the exact memory address and size of every function and variable.
3. **Memory Sections (Flash vs SRAM)**:
   * **`.text`**: Program code and interrupt vector table (Stored in Flash).
   * **`.rodata`**: Read-only constants, string literals (Stored in Flash).
   * **`.data`**: Initialized global and static variables (Stored in Flash, copied to RAM at startup).
   * **`.bss`**: Uninitialized global and static variables (Allocated in RAM, zeroed at startup).
4. **RAM Organization: Stack vs Heap**:
   * **The Stack**: Grows downward in RAM; automatically stores local variables, return addresses, and interrupt context.
   * **The Heap**: Dynamic memory allocation via `malloc()` and `free()`.
   * **Racing Directive**: Why dynamic memory is strictly banned in safety-critical vehicle controllers (fragmentation risk, unpredictable allocation latency).
5. **Basic Debugging & Simple Input**:
   * Setting hardware breakpoints in CubeIDE and stepping through code (`F5`, `F6`).
   * Reading a simple push button on `PA0` without complex interrupt configuration.

---

## Daily Operational Guide

* **Day 1 (Monday) — Build Pipeline**:
  * Understand the 4 stages: Preprocessing $\rightarrow$ Compiling $\rightarrow$ Assembling $\rightarrow$ Linking.
  * Learn what `.c`, `.h`, `.o`, `.elf`, and `.hex` files contain.
* **Day 2 (Tuesday) — Memory Layout & Linker Script**:
  * Live session (45 mins): Walkthrough of the `.ld` linker script and reading the `.map` file.
  * Inspect your Week 1 `.map` file to find where `main()` and your variables live in Flash and RAM.
* **Day 3 (Wednesday) — Stack vs Heap**:
  * Video drop & study: How the Stack grows downward and stores function call frames.
  * Understand stack overflow dangers and why `malloc()` is avoided in racecar firmware.
* **Day 4 (Thursday) — Simple Debugger Lab & Office Hours**:
  * 30-45 min drop-in session: Step Over (`F6`), Step Into (`F5`), and observing variables update in real time in CubeIDE.
* **Day 5 (Friday) — Simple Button Input Lab**:
  * Hands-on lab: Connect a push-button to `PA0` with internal pull-up in Proteus.
  * Read input using `HAL_GPIO_ReadPin()` to toggle an LED (no complex interrupt math).
* **Day 6 (Saturday) — Submission Deadline**:
  * Submit short report with a screenshot of your `.map` file and a video/screenshot of your button controlling an LED in Proteus.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute check-in: explain the 4 build stages, the difference between Stack and Heap, and what the `.map` file shows.
