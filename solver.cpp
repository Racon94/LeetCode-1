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
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i=0;(size_t)i < nums.size();i++)
			for(int j=i+1;(size_t)j < nums.size();j++)
				if (nums[i] + nums[j] == target) return vector <int > {i, j};
		return vector <int > {0, 0};
	}

	//#2 Add Two Numbers
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int overflow = 0;
		ListNode* head = new ListNode(0);
		auto tail = head;
		while (l1 || l2) {
			if (l1) {
				overflow += l1->val; 
				l1 = l1->next;
			}
			if (l2) {
				overflow += l2->val;
				l2 = l2->next;
			}
			tail->next = new ListNode(overflow % 10);
			tail = tail->next;
			overflow /= 10;
		}
		if (overflow)tail->next = new ListNode(overflow);
		return head->next;
	}

	//#92 Reverse Linked List II
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		int idx = 0;
		ListNode* pre = new ListNode(0);
		pre->next = head;
		head = pre;
		ListNode* tail = new ListNode(0);
		ListNode* start = new ListNode(0);
		ListNode* cut = new ListNode(0);
		while (head && idx<=n) {
			if (idx == m - 1) {
				cut = head;
			}
			if (idx == m) {
				tail = new ListNode(head->val);
				start = tail;
			};
			if (idx > m and idx <= n) {
				auto tmp = new ListNode(head->val);
				tmp->next = start;
				start = tmp;
			}
			if (idx == n) {
				cut->next = start;
				if (head->next) {
					tail->next = head->next;
				}
			}
			idx++;
			head = head->next;
		}
		return pre->next;
	}

	//#101 Symmetric Tree
	bool isSymmetric(TreeNode* root) {
		if (!root)return true;
		return isSymmetricHelper(root->left, root->right);
	}

	bool isSymmetricHelper(TreeNode* left ,TreeNode* right) {
		if (!left && !right) return true;
		if ( (!left || !right) || left->val != right->val) return false;
		return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
	}

	//#102 Binary Tree Level Order Traversa
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector< vector<int> > ret;
		levelOrderHelper(ret , root, 0);
		return ret;
	}

	void levelOrderHelper(vector<vector<int>>& nums, TreeNode* root , int layer) {
		if (root == NULL) return;
		if (nums.size() < layer+1) { 
			nums.push_back(vector<int>()); 
		}
		nums[layer].push_back(root->val);
		levelOrderHelper(nums, root->left, layer + 1);
		levelOrderHelper(nums, root->right, layer + 1);
	}
	
};


int main() {
	string in1 = "(1,2,3,4,5,6)";
	string in2 = "(5,6,4)";
	auto l1 = buildList(in1,',');
	auto l2 = buildList(in2,',');
	auto solver = new Solution();
	printList(solver->reverseBetween(l1, 1,6));
	return 0;
}