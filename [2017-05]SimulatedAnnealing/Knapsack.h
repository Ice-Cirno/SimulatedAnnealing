#pragma once
#include "SA.h"
#include<fstream>
#include<string>

class Knapsack : public SA<bool>
{
private:
	double cap;
	double * weight;
	double * value;

	double getweight(bool*);

	std::string FileIn;
	std::ifstream fin;

protected:
	bool ReadFile();
	void Init();
	void GenerateNew();
	double Estimate(bool*);

public:
	Knapsack();
	void setFileIn(const std::string&);
	virtual ~Knapsack();
};

