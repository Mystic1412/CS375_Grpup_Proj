INPUTS := inputs/Large_inputs.txt
OUTPUTS := inputs/fifo.txt inputs/lfu.txt inputs/rand.txt

#######################################
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Target executable
TARGET = warehouse

# Source files
SRC = main.cpp Warehouse.cpp FIFO.cpp LeastFrequentlyUsed.cpp RandomlyUsed.cpp
HEADERS = Warehouse.h

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: clean $(TARGET) clear run

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
