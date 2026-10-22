# Instructor Live Demonstration Guide: GCC Pipeline, Makefile & Git

This folder contains a complete minimal C project to demonstrate the **4-stage C compilation pipeline**, **Makefile automation**, and **Git version control** live to students.

---

## Part 1: Manual Step-by-Step GCC Commands

Navigate to this folder in PowerShell or Terminal:
```powershell
cd D:\APEXALL\EmbdeddSystem\Weeks\Week-1-GPIO-Arch\Lab
```

### Stage 1: Preprocessing (`gcc -E`)
Expands `#include` files and substitutes all `#define` macros:
```bash
gcc -E main.c -o main.i
```
* **What to show students**: Open `main.i` in VS Code / Notepad.
* Point out:
  * Hundreds of lines from `stdio.h` are pasted in.
  * `TEAM_NAME` is replaced with `"Apex Racing Team"`.
  * `#include "math_utils.h"` is replaced with the function prototypes.

---

### Stage 2: Compilation to Assembly (`gcc -S`)
Translates preprocessed C code into human-readable assembly instructions:
```bash
gcc -S main.i -o main.s
```
* **What to show students**: Open `main.s`.
* Point out:
  * Assembly instructions (`mov`, `add`, `call`, `push`, `pop`).
  * Function labels like `main:`.

---

### Stage 3: Assembling to Object Machine Code (`gcc -c`)
Converts assembly text into relocatable machine-code binary files (`.o`):
```bash
gcc -c main.s -o main.o
gcc -c math_utils.c -o math_utils.o
```
* **What to show students**: Open `main.o` in Notepad (it displays unreadable binary).
* Use `objdump` to view the disassembly:
  ```bash
  objdump -d main.o
  ```

---

### Stage 4: Linking to Final Executable (`gcc`)
Resolves symbol addresses and links `main.o` with `math_utils.o`:
```bash
gcc main.o math_utils.o -o app.exe
```
* Execute the binary:
  ```bash
  .\app.exe
  ```

---

## Part 2: Automated Compilation with Makefile

Show students why manual compilation is impractical for large firmware projects and how `make` automates it:

1. **Clean all artifacts**:
   ```bash
   mingw32-make clean
   ```
2. **Build the project automatically**:
   ```bash
   mingw32-make
   ```
   * Notice: `make` compiles both `.c` files into `.o` files, then links them into `app.exe`.
3. **Run the built application**:
   ```bash
   mingw32-make run
   ```
4. **Show Incremental Rebuilding**:
   * Run `mingw32-make` again without modifying files.
   * Point out: `make: Nothing to be done for 'all'.`
   * Now modify a single comment in `main.c` and run `mingw32-make`.
   * Point out: only `main.c` recompiles; `math_utils.c` is NOT recompiled!

---

## Part 3: Live Git Demonstration

Show students practical Git commands right in this folder:

1. **Check status of modified files**:
   ```bash
   git status
   ```
2. **Show exact line changes**:
   ```bash
   git diff main.c
   ```
3. **Stage and commit changes**:
   ```bash
   git add main.c
   git commit -m "feat(lab): demonstrate live compilation and git"
   ```
4. **Inspect clean commit history**:
   ```bash
   git log --oneline -n 5
   ```
