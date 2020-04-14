#include "../Solution.h"

//binary search within [low,high]
int findK(vector<int> nums, int num , int low , int high) {
	int i = low, j = high , m = (i+j)/2;
	while (i < j) {
		if (nums[m] == num) break;
		if (nums[m] < num) i = m+1;
		else j = m-1;
		m = (i + j) / 2;
	}
	return m;
}
/*Moving pattern
	nums1----i1----j1
	nums2----i2----j2
	i1 link j2
	i2 link j1
*/
vector<vector<int>> Solution::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	int i1=0,i2 = 0, j1 = 0 , j2 = 0, sum = nums1[0] + nums2[0];
	vector<vector<int>>  ret = { {nums1[0] , nums2[0]} };
	while (ret.size() < k) {
		// decide side to move 1 step
		if (i1 >= nums1.size() - 1) {
			while(ret.size() < k && ++j2 < nums2.size() ) 
				ret.push_back(vector<int> { nums1[i1], nums2[j2] });
			break;
		}
		if (i2 >= nums2.size() - 1) {
			while (ret.size() < k && ++j1 < nums1.size())
				ret.push_back(vector<int> { nums1[j1], nums2[i2] });
			break;
		}
		if (nums1[i1+1] + nums2[j2] < nums2[i2+1] + nums1[j1]) {
			sum = nums1[++i1] + nums2[j2];
			ret.push_back(vector<int> { nums1[i1], nums2[j2] });
			while (j1 < nums1.size() && ret.size()<k && nums2[i2] + nums1[++j1] < sum) {
				ret.push_back(vector<int> { nums1[j1], nums2[i2] }); 
			}
		}
		else {
			sum = nums2[++i2] + nums1[j1];
			ret.push_back(vector<int> { nums1[j1], nums2[i2] });
			while (j2 < nums2.size() && ret.size() < k && nums1[i1] + nums2[++j2] < sum) {
				ret.push_back(vector<int> { nums1[i1], nums2[j2] });
			}
		}

	}
	return ret;
}