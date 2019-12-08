#pragma once
#include <iostream>
#include <vector>
#include "utils.h"
#include "mTree.h"
#include "mList.h"
#include "Solution.h"
using namespace std;


int main() {
	string in1 = "0123456789";
	string in2 = "(2,3,4,5)";
	//ListNode* l1 = buildList(in1, ',');
	//ListNode* l2 = buildList(in2, ',');
	auto solver = new Solution();
	auto ret = solver->convert(in1,1);
	cout << ret << endl; 
	return 0;
}
