INPUTS := inputs/inputs.txt
OUTPUTS := inputs/fifo.txt inputs/lru.txt inputs/rand.txt

#######################################
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Target executable
TARGET = warehouse

# Source files
SRC = Main.cpp Warehouse.cpp FIFO.cpp LeastRecentlyUsed.cpp RandomlyUsed.cpp
HEADERS = Warehouse.h

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: clear $(TARGET)

# Link executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile objects
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ) $(TARGET).exe $(TARGET) $(OUTPUTS)

# Clear terminal
clear:
	clear

# Run
run: $(TARGET)
	./$(TARGET) $(INPUTS) $(OUTPUTS)
