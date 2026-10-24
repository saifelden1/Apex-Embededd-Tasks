# Week 1 — Build Pipeline, Makefile & Git Workflow

[![Week](https://img.shields.io/badge/Week-1%20of%206-blue.svg)](#)
[![Focus](https://img.shields.io/badge/Focus-GCC%20Pipeline%20%7C%20Makefile%20%7C%20Git-brightgreen.svg)](#)
[![Lab](https://img.shields.io/badge/Hands--on-Lab%20Directory-orange.svg)](Lab/)

Welcome to **Week 1** of the Apex Racing Team Embedded Systems Onboarding Track.

---

## Weekly Objectives
1. **The 4-Stage C Build Pipeline**:
   * **Preprocessing (`gcc -E`)**: Expands `#include`, evaluates `#define` macros, strips comments.
   * **Compiling (`gcc -S`)**: Translates high-level C code to human-readable Cortex-M / x86 assembly.
   * **Assembling (`gcc -c`)**: Converts assembly text into machine-code relocatable object files (`.o`).
   * **Linking (`gcc -o`)**: Resolves symbol addresses and links multiple `.o` files into the final executable (`.elf`/`.exe`).
2. **Build Automation with Makefile**:
   * Direct toolchain instructions (`CC`, `CFLAGS`, targets, prerequisites, recipes). Every CubeIDE project secretly generates one in `Debug/makefile`.
   * Incremental compilation benefits and target execution (`all`, `run`, `clean`).
3. **Output Build Artifacts**:
   * Inspecting intermediate files (`.i`, `.s`, `.o`, `.map`, `.elf`, `.hex`).
4. **Git & GitHub Team Directives**:
   * Clone, branch convention (`your-name/feature`), stage, commit, diff, and pull request.
   * **AI Policy**: AI tools permitted for learning, but **100% mandatory 1-on-1 oral defense**.

---

## Required Software & Toolchain Dependencies

All students must download and set up these core dependencies before Wednesday's live session:

1. **Git for Windows (with Git Bash)**
   * **Download**: [git-scm.com/download/win](https://git-scm.com/download/win)
   * **Purpose**: Terminal environment (`bash`), Git version control, POSIX command execution (`rm`, `cat`, `tail`).

2. **MinGW-w64 (GCC & Make)**
   * **Download**: [WinLibs Standalone Build](https://winlibs.com/) or [w64devkit Release](https://github.com/skeeto/w64devkit/releases)
   * **Purpose**: Host C compiler (`gcc`) and build automation tool (`mingw32-make` / `make`) for Week 1 CLI compilation exercises. Ensure the `bin` directory is added to your system `PATH`.

3. **STM32CubeIDE (v1.14.0 or newer)**
   * **Download**: [STMicroelectronics STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
   * **Purpose**: Primary embedded IDE, ARM GCC toolchain (`arm-none-eabi-gcc`), HAL libraries, and SWD debugger for Weeks 2–6.

4. **STM32CubeProgrammer**
   * **Download**: [STMicroelectronics STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)
   * **Purpose**: Flashing utility, ST-Link firmware updater, and raw memory viewer.

5. **Proteus 8 Professional (v8.13 or newer)**
   * **Reference**: [Labcenter Electronics](https://www.labcenter.com/)
   * **Purpose**: Circuit schematic and virtual microcontroller simulation environment for all tasks.

---

## Daily Operational Guide & Curated Links

* **Day 1 (Monday) — Build Pipeline**:
  * 📺 [C Compiling Process Video](https://www.youtube.com/watch?v=N2y6csonII4)
  * Understand the 4 stages: Preprocess $\rightarrow$ Compile $\rightarrow$ Assemble $\rightarrow$ Link.
* **Day 2 (Tuesday) — Git & Toolchain**:
  * 📺 [Git & GitHub Tutorial](https://www.youtube.com/watch?v=mAFoROnOfHs)
  * Clone repository locally and verify local `gcc` and `make` installation.
* **Day 3 (Wednesday) — Live Session: Hands-on CLI Compilation**:
  * 45-min live session in [`Weeks/Week-1-GPIO-Arch/Lab/`](Lab/):
  * Execute manual GCC commands step-by-step (`gcc -E`, `gcc -S`, `gcc -c`, `gcc -o`).
  * Open and inspect `main.i`, `main.s`, and `main.o` live.
* **Day 4 (Thursday) — Makefile Automation**:
  * Study `Makefile` syntax (targets, prerequisites, recipes).
  * Build project using `mingw32-make`; test `mingw32-make run` and `mingw32-make clean`.
  * 📺 **CMake Brief (Self-Study)**: [CMake Tutorial Playlist (Watch Videos 1 to 5)](https://www.youtube.com/watch?v=vGiLCneOyX4&list=PLkH1REggdbJpG8fHZvivt-5Hlg3UZcJrK)
* **Day 5 (Friday) — Offline Workshop Day**:
  * Meet at team workshop: resolve local compiler path issues and practice Git commands.
* **Day 6 (Saturday) — Week 1 Submission**:
  * Submit screenshots of manual GCC stage outputs (`.i`, `.s`, `.o`, execution) and `git status` by 11:59 PM.
* **Day 7 (Sunday) — Friendly 1-on-1 Oral Check-in**:
  * 10-minute check-in: explain the 4 compilation stages and why Makefiles automate builds.
