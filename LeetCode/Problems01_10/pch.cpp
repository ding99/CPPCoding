// pch.cpp: source file corresponding to the pre-compiled header
//#include <iostream>
#include "pch.h"
#include "Problems10.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.

int add(int a, int b) { return a + b; }
void add1() { std::cout << add(2, 3) << std::endl; }
void add2() { std::cout << add(5, 6) << std::endl; }

void TwoSum() {
	Solution solution;
	std::vector<int> data = { 2, 7, 11, 15 };
	int sum = 9;

	std::vector<int> results = solution.twoSum(data, sum);

	std::cout << results.at(0) << ", " << results.at(1) << std::endl;
}

