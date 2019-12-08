#include "../Solution.h"

//#143 Reorder List
void reorderList(ListNode* head) {
	int idx = 0, len = 0;
	ListNode* ohead = NULL;
	ListNode* otail = ohead;
	ListNode* ehead = new ListNode(0);
	ListNode* etail = ehead;
	ListNode* prehead = head;
	while (head) { len++; head = head->next; }
	if (len < 2) return;
	head = prehead;
	while (head) {
		if (idx >= len / 2) {
			if (ohead) {
				ohead = new ListNode(head->val);
				ohead->next = otail;
				otail = ohead;
			}
			else {
				ohead = new ListNode(head->val);
				otail = ohead;
			}
		}
		else {
			etail->next = new ListNode(head->val);
			etail = etail->next;
		}
		idx++;
		head = head->next;
	}
	head = prehead;
	if (ehead)ehead = ehead->next;
	if (ehead)ehead = ehead->next;
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