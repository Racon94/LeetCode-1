#include "../Solution.h"

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