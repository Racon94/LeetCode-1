#pragma once

#ifndef MTREE_H
#define MTREE_H

#include <vector>
#include <iostream>
#include "utils.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

TreeNode* buildTree(std::string in , char p = ' ');

TreeNode* buildTree(std::vector<std::string> values, int idx);

void printTree(TreeNode* root);

#endif