# Instructor Live Demonstration Guide: Git Bash Edition

This guide is optimized for **Git Bash**. Follow these exact terminal commands during your live demonstration session.

---

## 1. Open Terminal & Navigate (Git Bash)

Open **Git Bash** and navigate to this lab directory:
```bash
cd /d/APEXALL/EmbdeddSystem/Weeks/Week-1-GPIO-Arch/Lab
pwd
ls -la
```

---

## 2. Part 1: The 4 Manual GCC Stages

### Stage 1: Preprocessing (`gcc -E`)
Expands `#include` files and substitutes `#define` macros:
```bash
gcc -E main.c -o main.i
```
* **Live Inspection in Git Bash**:
  ```bash
  tail -n 25 main.i
  ```
  * Point out to students: `TEAM_NAME` is gone, replaced with `"Apex Racing Team"`. `#include "math_utils.h"` is replaced by function prototypes.

---

### Stage 2: Compilation to Assembly (`gcc -S`)
Translates preprocessed C code into Cortex / x86 assembly instructions:
```bash
gcc -S main.i -o main.s
```
* **Live Inspection in Git Bash**:
  ```bash
  cat main.s | head -n 30
  ```
  * Point out: Assembly instructions (`mov`, `add`, `call`), registers, and labels (`main:`).

---

### Stage 3: Assembling to Machine Code (`gcc -c`)
Converts assembly text into relocatable machine-code binary files (`.o`):
```bash
gcc -c main.s -o main.o
gcc -c math_utils.c -o math_utils.o
```
* **Live Inspection**:
  * Point out: `file main.o` shows relocatable object file.
  * Disassemble machine code with `objdump`:
    ```bash
    objdump -d main.o
    ```

---

### Stage 4: Linking to Final Executable (`gcc`)
Resolves symbol addresses and links `main.o` with `math_utils.o`:
```bash
gcc main.o math_utils.o -o app.exe
./app.exe
```

---

## 3. Part 2: Automated Compilation with Makefile

Show students how Makefiles automate these 4 stages in a single command:

1. **Clean all generated files**:
   ```bash
   mingw32-make clean
   ls
   ```
2. **Build the entire project**:
   ```bash
   mingw32-make
   ```
   * Notice: `make` automatically runs `gcc -c` on both source files and links `app.exe`.
3. **Execute immediately**:
   ```bash
   mingw32-make run
   ```
4. **Demonstrate Incremental Rebuilding**:
   * Run `mingw32-make` again:
     ```bash
     mingw32-make
     ```
     Outputs: `make: Nothing to be done for 'all'.`
   * Touch `main.c` (or edit a comment):
     ```bash
     touch main.c
     mingw32-make
     ```
     Point out: only `main.c` recompiles; `math_utils.c` is NOT recompiled!

---

## 4. Part 3: Live Git Workflow in Git Bash

Demonstrate daily engineering Git commands right inside Git Bash:

1. **Inspect status of files**:
   ```bash
   git status
   ```
2. **Inspect changes line-by-line**:
   ```bash
   git diff
   ```
3. **Stage, commit, and inspect history**:
   ```bash
   git add Makefile DEMO_GUIDE.md
   git commit -m "feat(lab): optimize makefile and guide for Git Bash"
   git log --oneline -n 5
   ```
