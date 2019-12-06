#include "Solution.h"

//#101 Symmetric Tree
bool Solution::isSymmetric(TreeNode* root) {
	if (!root)return true;
	return isSymmetricHelper(root->left, root->right);
}

bool Solution::isSymmetricHelper(TreeNode* left, TreeNode* right) {
	if (!left && !right) return true;
	if ((!left || !right) || left->val != right->val) return false;
	return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}