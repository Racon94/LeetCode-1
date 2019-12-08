#include "../Solution.h"

//#2 Add Two Numbers
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
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