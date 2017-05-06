# SimulatedAnnealing @201705

all: TSP.o main.o
	g++ -o SA.exe main.o TSP.o -std=c++11

TSP.o: SA.h TSP.h TSP.cpp
	g++ -c TSP.cpp -std=c++11

main.o: main.cpp SA.h TSP.h TSP.cpp
	g++ -c main.cpp TSP.cpp -std=c++11

clean:
	rm *.o *.exe