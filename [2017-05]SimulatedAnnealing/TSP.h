#pragma once
#include "SA.h"
#include<fstream>
#include<string>

class TSP :public SA<int>
{
private:
	double * x, * y;
	double ** distance;

	std::string FileIn;
	std::ifstream fin;
	
	template<typename T>
	void swap(T&, T&);

protected:
	bool ReadFile();
	void Init();
	void GenerateNew();
	double Estimate(int*);

public:
	TSP();
	void setFileIn(const std::string&);
	virtual ~TSP();
};

template<typename T>
void TSP::swap(T & t1, T & t2){
	T temp = t1;
	t1 = t2;
	t2 = temp;
}
