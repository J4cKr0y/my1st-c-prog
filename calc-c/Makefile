# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -v
LDFLAGS = -lm

# Default rules
all: calc

# Executable's rules
calc: main.o functions.o
	$(CC) main.o functions.o -o calc $(LDFLAGS)

# Object files rules
main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

# Cleaning
clean:
	rm -f *.o calc

.PHONY: all clean
