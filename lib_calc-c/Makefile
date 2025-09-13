# === Variables ===
CC = gcc
AR = ar

PICFLAGS = -fPIC
LDFLAGS = -lm

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

CFLAGS = -Wall -Wextra -O2 -I$(SRC_DIR)/lib/staticCalc -I$(SRC_DIR)/lib/dynamicCalc

# Sources
STATIC_SRC = $(SRC_DIR)/lib/staticCalc/static_calc.c
DYNAMIC_SRC = $(SRC_DIR)/lib/dynamicCalc/dynamic_calc.c
MAIN_SRC = $(SRC_DIR)/app/main.c

# Objects
STATIC_OBJ = $(BUILD_DIR)/static_calc.o
DYNAMIC_OBJ = $(BUILD_DIR)/dynamic_calc.o

# Dependancies
STATIC_DEP = $(STATIC_OBJ:.o=.d)
DYNAMIC_DEP = $(DYNAMIC_OBJ:.o=.d)
MAIN_OBJ = $(BUILD_DIR)/main.o
MAIN_DEP = $(MAIN_OBJ:.o=.d)

# Librairies
STATIC_LIB = $(BUILD_DIR)/libstaticCalc.a
DYNAMIC_LIB = $(BIN_DIR)/libdynamicCalc.so

# Exe
TARGET = $(BIN_DIR)/lib_calc-c

# === Rules ===

all: $(TARGET)

# Compilation of  objects with dependancies
$(BUILD_DIR)/%.o: $(SRC_DIR)/lib/staticCalc/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/lib/dynamicCalc/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(PICFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/main.o: $(MAIN_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Static lib
$(STATIC_LIB): $(STATIC_OBJ)
	$(AR) rcs $@ $^

# Dynamic lib
$(DYNAMIC_LIB): $(DYNAMIC_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) -shared -o $@ $^

# Main exe
$(TARGET): $(MAIN_OBJ) $(STATIC_LIB) $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) $< -o $@ \
		-I$(SRC_DIR)/lib/staticCalc \
		-I$(SRC_DIR)/lib/dynamicCalc \
		-L$(BUILD_DIR) -lstaticCalc \
		-L$(BIN_DIR) -ldynamicCalc \
		$(LDFLAGS)

# Cleaning
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run
run: all
	./$(TARGET)

# Include dependency files
-include $(STATIC_DEP) $(DYNAMIC_DEP) $(MAIN_DEP)
