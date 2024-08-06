CC = g++
FLAGS = -g -Wall

TARGET = learndsa

RM = rm -rf

all: common BubbleSort QuickSort SelectionSort Heap
	$(CC) $(FLAGS) -o $(TARGET) \
	main.cc \
	common.o \
	BubbleSort.o \
	SelectionSort.o \
	QuickSort.o \
	Heap.o
	./$(TARGET)

common: common.cc common.hh
	$(CC) $(FLAGS) -c common.cc common.hh

BubbleSort: BubbleSort.cc BubbleSort.hh
	$(CC) $(FLAGS) -c BubbleSort.cc BubbleSort.hh

QuickSort: QuickSort.cc QuickSort.hh
	$(CC) $(FLAGS) -c QuickSort.cc QuickSort.hh

SelectionSort: SelectionSort.cc SelectionSort.hh
	$(CC) $(FLAGS) -c SelectionSort.cc SelectionSort.hh

Heap: Heap.cc Heap.hh
	$(CC) $(FLAGS) -c Heap.cc Heap.hh

clean:
	$(RM) *.o *.gch $(TARGET)

