# Makefile
CXX_FLAG = --std=c++11 -g

list: main.o intlist.o
	g++ $(CXX_FLAG) -o list main.o intlist.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

intlist.o: intlist.cpp
	g++ -c $(CXX_FLAG) intlist.cpp

clean:
	rm -f list *.o
