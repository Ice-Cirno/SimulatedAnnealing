#pragma once
#define DEBUG
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>

#define TEMPERATURE_INIT 10000000000000000.0
#define ANEALING_COEFF 0.999
#define TEMPERATURE_GOAL 0.001
#define RES 100

enum Max_or_Min { max = -1, min = 1 };

template<typename rootT>
class SA {
private:
	double Temperature;
	bool AcceptBadRoot(double);

protected:
	std::string FileIn;
	std::ifstream fin;
	
	int N;
	Max_or_Min _max_or_min;
	rootT* best_root;
	rootT* curr_root;
	rootT* new_root;

	virtual void ReadFile() = 0;
	virtual void Init() = 0;
	virtual void GenerateNew() = 0;
	virtual double Estimate(rootT*) = 0;

public:
	SA();
	virtual ~SA();
	virtual void Do() final;
	virtual bool setFileIn(const std::string&) final;
};

template<typename rootT>
bool SA<rootT>::AcceptBadRoot(double gain){
	double prob = exp(-gain / Temperature);
	double random_number = (double)(rand() / (double)RAND_MAX);
	return (random_number <= prob) ? true : false;
}

template<typename rootT>
SA<rootT>::SA() :Temperature(TEMPERATURE_INIT) {
	srand((unsigned)time(0));
}

template<typename rootT>
SA<rootT>::~SA(){
	/*if (best_root) delete[] best_root;
	if (curr_root) delete[] curr_root;
	if (new_root) delete[] new_root;*/
}

template<typename rootT>
void SA<rootT>::Do() {
	double gain, bestgain;

	if (!fin) {
		std::cout << "failed to open input file..." << std::endl;
		return;
	}
	ReadFile();
	Init();
	while (Temperature > TEMPERATURE_GOAL) {
		int i = RES;
		while (--i) {
			GenerateNew();
			gain = static_cast<int>(_max_or_min) * (Estimate(new_root) - Estimate(curr_root));
			bestgain = static_cast<int>(_max_or_min) * (Estimate(new_root) - Estimate(best_root));
			if (gain < 0 || AcceptBadRoot(gain)) {
				//fresh currroot...
				for (int i = 0; i < N; ++i)
					curr_root[i] = new_root[i];
			}
			if (bestgain < 0) {
				//fresh bestroot...
				for (int i = 0; i < N; ++i)
					best_root[i] = new_root[i];
#ifdef DEBUG
				std::cout << "Temperature now is " << Temperature << std::endl;
				std::cout << "The best root obtained so far is " << Estimate(best_root) << std::endl;
				for (int i = 0; i < N; i++)
					std::cout << best_root[i] << " "; std::cout << std::endl;
#endif // DEBUG
			}
			
		}
		Temperature *= ANEALING_COEFF;
	}
	std::cout << "The best root finally obtained is " << Estimate(best_root) << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << best_root[i] << " "; std::cout << std::endl;
}

template<typename rootT>
bool SA<rootT>::setFileIn(const std::string& _name) {
	FileIn = _name;
	fin.open(FileIn);
	if (!fin) {
		std::cout << "Cannot open " << FileIn << std::endl;
		return false;
	}
	std::cout << FileIn << " opened successfully." << std::endl;
	return true;
}

