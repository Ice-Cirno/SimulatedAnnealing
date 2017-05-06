#include "TSP.h"
#include<fstream>
#include<iostream>

void TSP::setFileIn(const std::string& _name) {
	FileIn = _name;
}

bool TSP::ReadFile() {
	fin.open(FileIn);
	if (!fin) {
		std::cout << "Cannot open " << FileIn << std::endl;
		return false;
	}
	else{
		std::cout << FileIn << " opened." << std::endl;
	}
	
	fin >> N;
	x = new double[N];
	y = new double[N];
	distance = new double*[N];
	for (int i = 0; i < N; ++i) {
		distance[i] = new double[N];
	}

	for (int i = 0; i < N; ++i) {
		fin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			fin >> distance[i][j];
		}
	}
	fin.close();
	return true;
}

void TSP::Init(){
	best_root = new int[N + 1];
	curr_root = new int[N + 1];
	new_root = new int[N + 1];
	for (int i = 0; i < N; ++i) {
		best_root[i] = curr_root[i] = new_root[i] = i;
	}
	best_root[N] = curr_root[N] = new_root[N] = 0;
}

void TSP::GenerateNew(){
	for (int i = 0; i < N; ++i) {
		new_root[i] = curr_root[i];
	}
	int r1 = rand() % (N - 1) + 1;
	int r2 = rand() % (N - 1) + 1;
	int pos1 = (r1 < r2) ? r1 : r2;
	int pos2 = (r1 < r2) ? r2 : r1;

	//swap the order between pos1/2...
	int limit = (pos2 - pos1 + 1) / 2;
	for (int k = 0; k < limit; ++k) {
		swap(new_root[pos1++], new_root[pos2--]);
	}
}

double TSP::Estimate(int * root)
{
	double cost = 0;
	for (int i = 0; i < N; ++i) {
		cost += distance[root[i]][root[i + 1]];
	}
	return cost;
}

TSP::TSP(){
	_max_or_min = min;
}


TSP::~TSP()
{/*
	if (x != nullptr) delete[] x;
	if (y != nullptr) delete[] y;
	if (distance != nullptr) {
		for (int i = 0; i < N; ++i) {
			if (distance[i] != nullptr) delete[] distance[i];
		}
		delete[] distance;
	}
*/}
