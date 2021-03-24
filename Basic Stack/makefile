main: main.o
	g++ -o main -std=c++11 main.o
main.o: stack.cpp main.cpp
	g++ -c -std=c++11 stack.cpp
	g++ -c -std=c++11 main.cpp
clean:
	-rm *.h.gch
	-rm *.o 
