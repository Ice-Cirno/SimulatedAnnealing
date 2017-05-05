#pragma once
#include<cstdlib>
#include<ctime>
#include<cmath>

#define TEMPERATURE_INIT 1000000000
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
	void Do();
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
	if (best_root) delete[] best_root;
	if (curr_root) delete[] curr_root;
	if (new_root) delete[] new_root;
}

template<typename rootT>
void SA<rootT>::Do() {
	double gain;

	ReadFile();
	Init();
	while (Temperature > TEMPERATURE_GOAL) {
		int i = RES;
		while (--i) {
			GenerateNew();
			gain = static_cast<int>(_max_or_min) * (Estimate(new_root) - Estimate(curr_root));
			if (gain < 0) {
				//fresh bestroot and currroot...
				for (int i = 0; i < N; ++i)
					best_root[i] = curr_root[i] = new_root[i];
#ifdef DEBUG
				cout << "The best root obtained so far is " << Estimate(best_root) << endl;
				for (int i = 0; i < n; i++)
					cout << best_root[i] << " "; cout << endl;
#endif // DEBUG
			}
			else if (AcceptBadRoot(gain)) {
				//fresh currroot...
				for (int i = 0; i < N; ++i)
					curr_root[i] = new_root[i];
			}
		}
		Temperature *= ANEALING_COEFF;
	}

}
