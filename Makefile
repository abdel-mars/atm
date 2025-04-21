# Compiler to use
CC = gcc

# Flags to pass to the compiler
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output binary
OUT = $(BIN_DIR)/atm

# Default target
all: directories $(OUT)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Link object files to create binary
$(OUT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program
run: all
	./$(OUT)

# Show help
help:
	@echo "Available targets:"
	@echo "  all    - Build the program (default)"
	@echo "  clean  - Remove build files"
	@echo "  run    - Build and run the program"
	@echo "  help   - Show this help message"

.PHONY: all clean run help directories
