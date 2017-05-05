#define DEBUG

#include<iostream>
#include"TSP.h"

int main() {
	TSP test;
	test.setFileIn("sample-input-files\\TSP-100.txt");
	test.Do();

	system("PAUSE");
	return 0;
}