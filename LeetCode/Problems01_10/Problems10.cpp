#include <iostream>
#include <vector>

#include "pch.h"
#include "Problems10.h"

/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target. You may assume that each input would have exactly one solution, and you may not use the same element twice.
**/

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++)
		for (int j = i + 1; j < nums.size(); j++)
			if (nums.at(i) + nums.at(j) == target)
				return { i, j };

	return {0, 0};
}

void Solution::veriList() {
	int nums[5] = {7,5,6,12,35};
	for (const int& n : nums)
		std::cout << n << " ";
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}