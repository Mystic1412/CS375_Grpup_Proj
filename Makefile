INPUTS := inputs/inputs.txt
OUTPUTS := inputs/fifo.txt inputs/lfu.txt inputs/lru.txt

#######################################
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = warehouse

# Source files
SRC = Main.cpp Warehouse.cpp FirstFit.cpp FirstFitDecreasing.cpp LeastFrequentlyUsed.cpp
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
	rm -f $(OBJ) $(TARGET).exe $(TARGET)

# Clear terminal
clear:
	clear

# Run
run: $(TARGET)
	./$(TARGET) $(INPUTS) $(OUTPUTS)
