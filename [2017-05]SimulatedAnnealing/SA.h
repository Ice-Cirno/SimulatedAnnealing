#pragma once
#define TEMPERATURE_INIT 1000000000
#define ANEALING_COEFF 0.999
#define TEMPERATURE_GOAL 0.001
#define RES 100

enum Max_or_Min { max = -1, min = 1 };

class SA {
private:
	double Temperature;
	bool AcceptBadRoot();

protected:
	Max_or_Min _max_or_min;
	void* best_root;
	void* curr_root;
	void* new_root;

	virtual void ReadFile() = 0;
	virtual void Init() = 0;
	virtual void GenerateNew() = 0;
	virtual double Estimate(void*) = 0;

public:
	SA();
	virtual ~SA();
	void Do();
};