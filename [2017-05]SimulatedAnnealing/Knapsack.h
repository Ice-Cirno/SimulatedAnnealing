#pragma once
#include "SA.h"

class Knapsack : public SA<bool>
{
private:
	double cap;
	double * weight;
	double * value;

	double getweight(bool*);

protected:
	void ReadFile();
	void Init();
	void GenerateNew();
	double Estimate(bool*);

public:
	Knapsack();
	virtual ~Knapsack();
};

