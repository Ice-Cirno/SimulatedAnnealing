#define DEBUG

#include<iostream>
#include<cstdlib>
#include"TSP.h"

int main() {
	TSP test;
	test.setFileIn("sample-input-files/TSP-100.txt");
	std::cout << "FileIn set." << std::endl;
	test.Do();

	//system("pause");
	return 0;
}