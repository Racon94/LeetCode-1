#pragma once

#ifndef MNODE_H
#define MNODE_H

#include <vector>
#include <iostream>
#include <string>

#include "utils.h"
#include "mJSON.h"

class Node {
public:
	int val;
	std::vector<Node*> neighbors;

	Node() {}

	Node(int _val, std::vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

Node* buildNode(std::string in);


#endif