#include "../Solution.h"

int Solution::evalRPN(vector<string>& tokens) {
	int nums[8000]{};
	int top = 0;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+")
		{
			nums[top - 2] = nums[top - 2] + nums[top - 1];
			top--;
		}
		else if (tokens[i] == "-")
		{
			nums[top - 2] = nums[top - 2] - nums[top - 1];
			top--;
		}
		else if (tokens[i] == "*")
		{
			nums[top - 2] = nums[top - 2] * nums[top - 1];
			top--;
		}
		else if (tokens[i] == "/")
		{
			nums[top - 2] =  nums[top - 2] / nums[top - 1];
			top --;
		}
		else
		{
			nums[top] = atof(tokens[i].c_str());
			top++;
		}
	}
	return nums[0];
}