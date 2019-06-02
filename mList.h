#pragma once



#ifndef MLIST_H
#define MLIST_H

#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(std::string in, char p);

void printList(ListNode* head);
#endif
