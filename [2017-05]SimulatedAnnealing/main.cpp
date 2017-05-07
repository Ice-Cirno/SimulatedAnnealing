#include<iostream>
#include<cstdlib>
#include<string>
#include"TSP.h"
#include"Knapsack.h"
#include"sample_gen.h"
using namespace std;

string inputfile;

void TSPtest() {
	TSP test;
	string defaultfile[]{ "sample-input-files/TSP-100.txt","sample-input-files/TSP-250.txt","sample-input-files/TSP-500.txt" };
	int filechoice = 0;
	while(true) {
		cout << "1. " << defaultfile[0] << endl
			<< "2. " << defaultfile[1] << endl
			<< "3. " << defaultfile[2] << endl
			<< "0. other" << endl
			<< "Please set input file: ";
		cin >> filechoice;

		if (filechoice == 0) {
			cout << "path = "; cin >> inputfile;
			break;
		}
		else if (filechoice > 0 && filechoice <= 3) {
			inputfile = defaultfile[filechoice - 1];
			break;
		}
		else { 
			cout << "Unexpected input!" << endl; 
			continue;
		}
	}
	if (test.setFileIn(inputfile))
		test.Do();
}

void Knapsacktest() {
	Knapsack test;
	string defaultfile[]{ "sample-input-files/Knapsack-100.txt","sample-input-files/Knapsack-250.txt","sample-input-files/Knapsack-500.txt" };
	int filechoice = 0;
	while(true) {
		cout << "1. " << defaultfile[0] << endl
			<< "2. " << defaultfile[1] << endl
			<< "3. " << defaultfile[2] << endl
			<< "0. other" << endl
			<< "Please set input file: ";
		cin >> filechoice;

		if (filechoice == 0) {
			cout << "path = "; cin >> inputfile;
			break;
		}
		else if (filechoice > 0 && filechoice <= 3) {
			inputfile = defaultfile[filechoice - 1];
			break;
		}
		else {
			cout << "Unexpected input!" << endl;
			continue;
		}
	}
	if (test.setFileIn(inputfile))
		test.Do();
}

int test() {
	cout << "/ * * * * * * * * * Welcome! * * * * * * * * * /" << endl;
	int choice = -1;
	while (choice) {
		choice = 0;
		cout << "...test start..." << endl;
		cout << "1. TSP" << endl
			<< "2. Knapsack Problem" << endl
			<< "0. exit" << endl
			<< "Please select test options: ";
		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
		case 1: 
			TSPtest();
			break;
		case 2: 
			Knapsacktest();
			break;
		default:
			cout << "Unexpected input!" << endl;
			break;
		}
		cout << "press ENTER to continue... " << endl;
		getchar();
		getchar();
	}

	//system("pause");
	return 0;
}

int main() {
	//Knapsack_sample_generator(100);
	//Knapsack_sample_generator(250);
	//Knapsack_sample_generator(500);
	test();
	return 0;
}