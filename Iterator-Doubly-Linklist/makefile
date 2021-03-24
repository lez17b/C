# Makefile of the Doubly Linked List w/ Iterators Program

main: main.o
	g++ -o main -std=c++11 main.o
	
main.o: main.cpp list.h list.hpp
	g++ -c -std=c++11 main.cpp
	g++ -c -std=c++11 list.h
clean:
	-rm *.h.gch
	-rm *.o
	-rm *.hpp.gch
