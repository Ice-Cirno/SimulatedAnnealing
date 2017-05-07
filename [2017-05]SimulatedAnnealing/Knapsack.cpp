#include "Knapsack.h"

double Knapsack::getweight(bool * root) {
	double total_weight = 0;
	for (int i = 0; i < N; ++i) {
		total_weight += root[i] * weight[i];
	}
	return total_weight;
}

void Knapsack::ReadFile() {
	fin >> cap >> N;
	weight = new double[N];
	value = new double[N];

	for (int i = 0; i < N; ++i) {
		fin >> weight[i];
	}
	for (int i = 0; i < N; ++i) {
		fin >> value[i];
	}

	fin.close();
}

void Knapsack::Init(){
	best_root = new bool[N];
	curr_root = new bool[N];
	new_root = new bool[N];
	for (int i = 0; i < N; ++i) {
		best_root[i] = curr_root[i] = new_root[i] = false;
	}
}

void Knapsack::GenerateNew() {
	for (int i = 0; i < N; ++i) {
		new_root[i] = curr_root[i];
	}
	do {
		int pos = rand() % N;
		new_root[pos] = (!new_root[pos]);
	} while (getweight(new_root) > cap);
}

double Knapsack::Estimate(bool * root) {
	double total_value = 0;
	for (int i = 0; i < N; ++i) {
		total_value += root[i] * value[i];
	}
	return total_value;
}


Knapsack::Knapsack() {
	_max_or_min = max;
}


Knapsack::~Knapsack() {
	/*******************************************************
	May crash on some platforms? Throw it to your compiler!
	if (weight) delete[] weight;
	if (value) delete[] value;
	********************************************************/
}
