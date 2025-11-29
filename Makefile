CC=g++
CFLAGS=-Wall -DBSD -DNDDEBUG
TARGET=warehouse
OFiles=warehouse.o
CPPFiles=MainInput.cpp Warehouse.cpp Warehouse.h

all:$(TARGET) run

run:
	./$(TARGET) inputs/input.txt inputs/output.txt
$(TARGET):$(OFiles)
	$(CC) $(CFLAGS) -o $@ $(OFiles)
$(OFiles): $(CPPFiles)
	$(CC) $(CFLAGS) -c $*.cpp
clean:
	rm -rf *.o $(TARGET)
