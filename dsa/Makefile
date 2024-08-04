CC = g++
FLAGS = -g -Wall

TARGET = learndsa

RM = rm -rf

all: Sorting 
	$(CC) $(FLAGS) -o $(TARGET) \
	main.cc \
	Sorting.o

Sorting: Sorting.cc Sorting.hh define.hh
	$(CC) $(FLAGS) -c Sorting.cc Sorting.hh define.hh

clean:
	$(RM) *.o *.gch $(TARGET)

