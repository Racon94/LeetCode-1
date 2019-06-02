#include "mTree.h"


TreeNode* buildTree(std::string in , char p ) {
	auto values = split(in.substr(1, in.length() - 2),p);
	return buildTree(values, 0);
}

TreeNode* buildTree(std::vector<std::string> values, int idx) {
	if (idx>=values.size() ||values[idx] == "null") return NULL;
	TreeNode* root = new TreeNode( parseInt(values[idx]) );
	root->left = buildTree(values, idx * 2 + 1);
	root->right = buildTree(values, idx * 2 + 2);
	return root;
}

void printTree(TreeNode* root) {
	if (root == NULL) return;
	std::cout << " ( " << root->val;
	printTree(root->left);
	printTree(root->right);
	std::cout << " ) ";
}

