#include "Solution.h"

//#92 Reverse Linked List II
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
	int idx = 0;
	ListNode* pre = new ListNode(0);
	pre->next = head;
	head = pre;
	ListNode* tail = new ListNode(0);
	ListNode* start = new ListNode(0);
	ListNode* cut = new ListNode(0);
	while (head && idx <= n) {
		if (idx == m - 1) {
			cut = head;
		}
		if (idx == m) {
			tail = new ListNode(head->val);
			start = tail;
		};
		if (idx > m&& idx <= n) {
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