#include "../Solution.h"

// quick sort intervals with first element
void mergeHelp(vector<vector<int>>& intervals , int low , int high) {
	if (high <= low) return;
	int i = low+1, j = high;
	auto key = intervals[low];
	while (true) {
		//left
		while (intervals[i][0] < key[0] || (intervals[i][0] == key[0] && intervals[i][1]<=key[1] )) {
			if (i == high)break;
			i++;
		}
		//right
		while (intervals[j][0] > key[0] || (intervals[j][0] == key[0] && intervals[j][1] >= key[1])) {
			if (j == low)break;
			j--;
		}
		if (i >= j)break;
		//swap
		intervals[i].swap(intervals[j]);
	}
	intervals[low].swap(intervals[j]);
	mergeHelp(intervals, low, j - 1);
	mergeHelp(intervals, j + 1, high);
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) {
	mergeHelp(intervals,0,intervals.size()-1); 
	vector<vector<int>> ret;
	if (intervals.size() == 0) return ret;
	ret.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++) {
		if (ret.back()[1] >= intervals[i][0] && ret.back()[1]< intervals[i][1]) {
			// change range
			ret.back()[1] = intervals[i][1];
		}
		else if(ret.back()[1] < intervals[i][0]){
			ret.push_back(intervals[i]);
		}
	}
	return ret;
}
