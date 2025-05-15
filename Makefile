CC = gcc
CFLAGS = -Wall -Wextra -I. -Isrc

# Source files
SRC = main.c \
	  src/algorithms/algos.c \
	  src/data_structures/linear.c \
	  src/data_structures/heap.c \
	  src/data_structures/tree.c \
	  src/hash/hash.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
TARGET = run

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean