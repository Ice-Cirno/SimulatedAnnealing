# SimulatedAnnealing @201705

all: TSP.obj main.obj
	g++ -o SimulatedAnnealing.exe TSP.obj main.obj


TSP.obj: SA.h TSP.h TSP.cpp
	g++ -c TSP.obj TSP.cpp -std=c++11

main.obj: main.cpp SA.h TSP.h TSP.cpp
	g++ -c main.obj main.cpp -std=c++11

clean:
	del *.obj *.exe