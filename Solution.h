#pragma once
#include <iostream>
#include <vector>
#include "utils.h"
#include "mTree.h"
#include "mList.h"

using namespace std;

class Solution {

public:

	//#1 two sum
	vector<int> twoSum(vector<int>& nums, int target);

	//#2 Add Two Numbers
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	//#92 Reverse Linked List II
	ListNode* reverseBetween(ListNode* head, int m, int n);

	//#101 Symmetric Tree
	bool isSymmetric(TreeNode* root);

	bool isSymmetricHelper(TreeNode* left, TreeNode* right);

	//#102 Binary Tree Level Order Traversa
	vector<vector<int>> levelOrder(TreeNode* root);

	void levelOrderHelper(vector<vector<int>>& nums, TreeNode* root, int layer);

	//#143 Reorder List
	void reorderList(ListNode* head);

	//#147 Insertion Sort List
	ListNode* insertionSortList(ListNode* head);

	//#148 Sort List
	ListNode* sortList(ListNode* head);


};