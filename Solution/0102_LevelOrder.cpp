#include "../Solution.h"

//#102 Binary Tree Level Order Traversa
vector<vector<int>> Solution::levelOrder(TreeNode* root) {
	vector< vector<int> > ret;
	levelOrderHelper(ret, root, 0);
	return ret;
}

void Solution::levelOrderHelper(vector<vector<int>>& nums, TreeNode* root, int layer) {
	if (root == NULL) return;
	if (nums.size() < layer + 1) {
		nums.push_back(vector<int>());
	}
	nums[layer].push_back(root->val);
	levelOrderHelper(nums, root->left, layer + 1);
	levelOrderHelper(nums, root->right, layer + 1);
}