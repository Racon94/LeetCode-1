#include "../Solution.h"

// 0 (1 2) [3 4] [5 6] 
class mHeap {
public:
	vector <int> heap;
	void build(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
			this->push(nums[i]);
	}
	void push(int x) {
		this->heap.push_back(x);
		int idx = this->heap.size() - 1;
		while (idx) {
			if (this->heap[idx] > this->heap[(idx-1)/ 2]) {
				int tmp = this->heap[idx];
				this->heap[idx] = this->heap[(idx - 1) / 2];
				this->heap[(idx - 1) / 2] = tmp;
			}
			idx = (idx - 1) / 2; 
		}
	}
	int pop(int idx) { // pop the idx number
		int ret = this->heap[idx];
		this->heap[idx] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		while (idx < this->heap.size()) {
			int l = -1, r = -1;
			if (2 * idx + 1 < this->heap.size()) l = this->heap[2 * idx + 1];
			else break;
			if (2 * idx + 2 < this->heap.size()) r = this->heap[2 * idx + 2];
			if (this->heap[idx] < l || this->heap[idx] < r) {
				if (l >= r) {
					int tmp = this->heap[idx];
					this->heap[idx] = l;
					idx = 2 * idx + 1;
					this->heap[idx] = tmp;
				}
				else {
					int tmp = this->heap[idx];
					this->heap[idx] = r;
					idx = 2 * idx + 2;
					this->heap[idx] = tmp;
				}
			}
			else break;
		}
		return ret;
	} 
	void showHeap() {
		for (int i = 0; i < this->heap.size(); i++)
			cout << this->heap[i] << " ";
		cout << endl;
	}
};

int Solution::findKthLargest(vector<int>& nums, int k) {
	auto heap = new mHeap(); 
	heap->build(nums);
	int ret = 0;
	for (int i = 0; i < k; i++) ret = heap->pop(0);
	return ret;
}
