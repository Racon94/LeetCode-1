#pragma once
#include "Solution.h"

using namespace std;


//#1 two sum
vector<int> Solution::twoSum(vector<int>& nums, int target) {
	for (int i = 0; (size_t)i < nums.size(); i++)
		for (int j = i + 1; (size_t)j < nums.size(); j++)
			if (nums[i] + nums[j] == target) return vector <int > {i, j};
	return vector <int > {0, 0};
}
	

