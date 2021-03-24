# Makefile of the Doubly Linked List w/ Iterators Program

main: main.o
	g++ -o driver.x -std=c++11 driver.o
	g++ -o mydriver.x -std=c++11 mydriver.o
main.o: driver.cpp mydriver.cpp tlist.h tnode.h tlist.hpp
	g++ -c -std=c++11 driver.cpp
	g++ -c -std=c++11 mydriver.cpp
	g++ -c -std=c++11 tnode.h
	g++ -c -std=c++11 tlist.h
clean:
	-rm *.h.gch
	-rm *.o
	-rm *.hpp.gch
