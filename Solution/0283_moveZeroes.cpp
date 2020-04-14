#include "../Solution.h"

void Solution::moveZeroes(vector<int>& nums) {
	int pos = 0, end = 0;
	while (end < nums.size()) {
		if (nums[end]) nums[pos++] = nums[end++];
		else end++;
	}
	while (pos < nums.size()) nums[pos++] = 0;
}