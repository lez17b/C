# makefile Linklist class-Struct

main: main.o linklist.o
	g++ -o main -std=c++11  main.o linklist.o
main.o: main.cpp
	g++ -c  -std=c++11  main.cpp
linklist.o: linklist.h linklist.cpp
	g++ -c  -std=c++11   linklist.h
	g++ -c  -std=c++11   linklist.cpp
clean:
	-rm *.h.gch
	-rm *.o