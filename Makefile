#File: Makefile
#Author: Taylor Dunlap
#Date: Nov 17, 2016
#Makefile for the binary search tree assignment

#compiler
CC = g++
#compiler flags
CFlags = -c -Wall
#executable
TARGET =  binary_search_tree
all: $(TARGET)

$(TARGET): main.o  binary_search_tree.o
	$(CC) main.o  binary_search_tree.o -o $(TARGET)

main.o: main.cpp  binary_search_tree.h
	$(CC) main.cpp $(CFlags)

library.o:  binary_search_tree.cpp  binary_search_tree.h
	$(CC) binary_search_tree.cpp $(CFlags)

clean:
	rm *.o $(TARGET) *~

