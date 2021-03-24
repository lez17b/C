# Makefile of TheInfix to postfix cod based on a Stack template
# By: Luciano Zavala

main: main.o
	g++ -o main -std=c++11 main.o
	
main.o: in2post.cpp Stack.h Stack.hpp
	g++ -c -std=c++11 in2post.cpp
	g++ -c -std=c++11 stack.h
clean:
	-rm *.h.gch
	-rm *.o
	-rm *.hpp.gch
