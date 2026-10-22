# ==============================================================
# Apex Racing Team — Minimal Makefile (Git Bash Optimized)
# ==============================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99

SRCS    = main.c math_utils.c
OBJS    = main.o math_utils.o
TARGET  = app.exe

# 1. Default Target: Builds executable
all: $(TARGET)

# 2. Link Target
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# 3. Compile Target
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 4. Run Target
run: $(TARGET)
	./$(TARGET)

# 5. Clean Target (Git Bash standard rm)
clean:
	rm -f $(OBJS) $(TARGET) *.i *.s
