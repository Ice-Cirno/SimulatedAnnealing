#pragma once
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>

double getrand_0to1() {
	return ((double)rand() / RAND_MAX);
}

bool Knapsack_sample_generator(int n, const std::string & _path = "") {
	std::string defaultFile("sample-input-files/Knapsack-" + std::to_string(n) + ".txt");
	std::string path = (_path == "") ? defaultFile : _path;
	std::ofstream fout;
	fout.open(path);
	if (!fout) {
		return false;
	}

	srand(time(0));
	fout << getrand_0to1() * 1000.0 + 1.0 << std::endl
		<< n << std::endl;
	for (int i = 0; i < n; ++i) {
		fout << getrand_0to1() * 100.0 + 0.0001 << ' ' << getrand_0to1() * 100.0 << std::endl;
	}

	fout.close();
	return true;
}

bool TSP_sample_generator(int n, const std::string & _path = "") {
	std::string defaultFile("sample-input-files/TSP-" + std::to_string(n) + ".txt");
	std::string path = (_path == "") ? defaultFile : _path;
	std::ofstream fout;
	fout.open(path);
	if (!fout) {
		return false;
	}

	srand(time(0));
	double * x = new double[n];
	double * y = new double[n];
	double ** distance = new double*[n];
	for (int i = 0; i < n; ++i) {
		distance[i] = new double[n];
	}

	for (int i = 0; i < n; ++i) {
		x[i] = getrand_0to1() * 1000.0;
		y[i] = getrand_0to1() * 1000.0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			double dx = x[i] - x[j];
			double dy = y[i] - y[j];
			distance[i][j] = distance[j][i] = sqrt(dx*dx + dy*dy);
		}
	}

	fout << n << std::endl;
	for (int i = 0; i < n; ++i) {
		fout << x[i] << ' ' << y[i] << std::endl;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fout << distance[i][j] << ' ';
		}
		fout << std::endl;
	}

	fout.close();
	return true;
}
