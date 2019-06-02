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
			if (idx > m && idx <= n) {
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
		if (nums.size() < layer + 1) { 
			nums.push_back(vector<int>()); 
		}
		nums[layer].push_back(root->val);
		levelOrderHelper(nums, root->left, layer + 1);
		levelOrderHelper(nums, root->right, layer + 1);
	}
	
	//#143 Reorder List
	void reorderList(ListNode* head) {
		int idx = 0 , len=0;
		ListNode* ohead = NULL;
		ListNode* otail = ohead;
		ListNode* ehead = new ListNode(0);
		ListNode* etail = ehead;
		ListNode* prehead = head;
		while (head) { len++;head = head->next; }
		if (len < 2) return;
		head = prehead;
		while (head) {
			if (idx>=len/2) {
				if (ohead) {
					ohead = new ListNode(head->val);
					ohead->next =otail;
					otail = ohead;
				}
				else 
					ohead = new ListNode(head->val);
					otail = ohead;
			}
			else {
				etail->next = new ListNode(head->val);
				etail = etail->next;
			}
			idx++;
			head = head->next;
		}
		head = prehead;
		if(ehead)ehead = ehead->next;
		if(ehead)ehead = ehead->next;
		while (ohead || ehead) {
			if (ohead) {
				head->next = new ListNode(ohead->val);
				ohead = ohead->next;
				head = head->next;
			}
			if (ehead) { 
				head->next = new ListNode(ehead->val);
				ehead = ehead->next;
				head = head->next;
			}
		}
	}

	//#147 Insertion Sort List
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		auto fast = head->next, slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = NULL;
		head = insertionSortList(head);
		fast = insertionSortList(fast);
		ListNode* cur = new ListNode(0);
		ListNode* tail = cur;
		while (head && fast) {
			if (head->val < fast->val) {
				tail->next = head;
				head = head->next;
			}
			else {
				tail->next = fast;
				fast = fast->next;
			}
			tail = tail->next;
		}
		if (head)tail->next = head;
		else tail->next = fast;

		return cur->next;
	}

	//#148 Sort List
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		auto fast = head->next, slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = NULL;
		head = sortList(head);
		fast = sortList(fast);
		ListNode* cur = new ListNode(0);
		ListNode* tail = cur;
		while (head && fast) {
			if (head->val < fast->val) {
				tail->next = head;
				head = head->next;
			}
			else {
				tail->next = fast;
				fast = fast->next;
			}
			tail = tail->next;
		}
		if (head)tail->next = head;
		else tail->next = fast;

		return cur->next;
	}
	

};


int main() {
	string in1 = "(1,2,3,5,6,4)";
	string in2 = "(5,6,4)";
	auto l1 = buildList(in1,',');
	auto l2 = buildList(in2,',');
	auto solver = new Solution();
	l1 = solver->sortList(l1);
	printList(l1);
	return 0;
}