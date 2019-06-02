#include "utils.h"


std::vector < std::string > split(std::string in , char p ) {
	std::vector < std::string > ret;
	for (int i = 0, st = 0; (size_t)i <= in.length(); i++) {
		if (in[i] == p || in[i] == '\0') { 
			ret.push_back(in.substr(st, i - st)); 
			st = ++i; 
		}
	}
	return ret;
}

int parseInt(std::string num) {
	int ret = 0;
	for (char c : num) {
		ret = ret * 10 + c - '0';
	}
	return ret;
}