#pragma once
#include "SA.h"

class TSP :public SA<int>
{
private:
	double * x, * y;
	double ** distance;
	
	template<typename T>
	void swap(T&, T&);

protected:
	void ReadFile();
	void Init();
	void GenerateNew();
	double Estimate(int*);

public:
	TSP();
	virtual ~TSP();
};

template<typename T>
inline void TSP::swap(T & t1, T & t2){
	T temp = t1;
	t1 = t2;
	t2 = temp;
}
