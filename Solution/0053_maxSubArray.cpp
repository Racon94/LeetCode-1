#include "../Solution.h"

int Solution::maxSubArray(vector<int>& nums) {
    int maxsum = -2147483648, tmpsum = 0;
    for (int i = 0; i < nums.size(); i++) {
        tmpsum += nums[i];
        maxsum = tmpsum > maxsum ? tmpsum : maxsum;
        if (tmpsum < 0)tmpsum = 0;
    }
    return maxsum;
}

// attention: all numbers are nagetive conditions. 