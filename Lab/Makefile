SHELL   = cmd.exe
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99

SRCS    = main.c math_utils.c
OBJS    = main.o math_utils.o
TARGET  = app.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	-del /q /f *.o *.i *.s *.exe 2>nul
