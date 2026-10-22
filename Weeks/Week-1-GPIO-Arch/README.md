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
