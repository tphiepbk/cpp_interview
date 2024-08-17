CC = g++
FLAGS = -g -Wall -std=c++20

TARGET = learncpp.out

RM = rm -rf

all: MemoryManagement SmartPointer StructClass OverloadOverride Casting ConstFunction Thread
	$(CC) $(FLAGS) -o $(TARGET) \
	main.cc \
	StructClass.o \
	MemoryManagement.o \
	OverloadOverride.o \
	Casting.o \
	ConstFunction.o \
	SmartPointer.o \
	Thread.o
	./$(TARGET)

MemoryManagement: MemoryManagement.cc MemoryManagement.hh define.hh
	$(CC) $(FLAGS) -c MemoryManagement.cc MemoryManagement.hh define.hh

SmartPointer: SmartPointer.cc SmartPointer.hh define.hh
	$(CC) $(FLAGS) -c SmartPointer.cc SmartPointer.hh define.hh

StructClass: StructClass.cc StructClass.hh define.hh
	$(CC) $(FLAGS) -c StructClass.cc StructClass.hh define.hh

OverloadOverride: OverloadOverride.cc OverloadOverride.hh define.hh
	$(CC) $(FLAGS) -c OverloadOverride.cc OverloadOverride.hh define.hh

Casting: Casting.cc Casting.hh define.hh
	$(CC) $(FLAGS) -c Casting.cc Casting.hh define.hh

ConstFunction: ConstFunction.cc ConstFunction.hh define.hh
	$(CC) $(FLAGS) -c ConstFunction.cc ConstFunction.hh define.hh

Thread: Thread.cc Thread.hh
	$(CC) $(FLAGS) -c Thread.cc Thread.hh define.hh

clean:
	$(RM) *.o *.gch $(TARGET)

