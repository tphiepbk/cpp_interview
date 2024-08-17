# *****************************************
# Author: tphiepbk
# *****************************************

CC = g++
FLAGS = -g -Wall -std=c++17

TARGET = leetcode.out

RM = rm -rf

all: <problem>
	$(CC) $(FLAGS) -o $(TARGET) \
	<problem>.o

<problem>: <filename>
	$(CC) $(FLAGS) -c <filename>

clean:
	$(RM) *.o *.gch $(TARGET)

