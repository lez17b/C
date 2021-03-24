# By: Luciano Zavala

main: proj4_driver.o
	g++ -o main -std=c++11 proj4_driver.o
	
main.o: proj4_driver.cpp bet.h bet.hpp
	g++ -c -std=c++11 proj4_driver.cpp
	g++ -c -std=c++11 bet.h
clean:
	-rm *.h.gch
	-rm *.o
	-rm *.hpp.gch
