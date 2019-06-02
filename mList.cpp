#include "mList.h"
#include "utils.h"

ListNode* buildList(std::string in, char p) {
	auto nums = split(in.substr(1,in.length()-2), p);
	ListNode* head = new ListNode(0);
	ListNode* tail = head;
	for (int i = 0;i < nums.size();i++) {
		tail->next = new ListNode(parseInt(nums[i]));
		tail = tail->next;
	}
	return head->next;
}

void printList(ListNode* head) {
	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}