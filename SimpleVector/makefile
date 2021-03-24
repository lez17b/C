main: main.o
	g++ -o main -std=c++11 main.o
main.o: simplevector.h main.cpp
	g++ -c -std=c++11 simplevector.h
	g++ -c -std=c++11 main.cpp
clean:
	-rm *.h.gch
	-rm *.o 
