#include "../Solution.h"

int Solution::lengthOfLongestSubstring(string s) {
	int ch[129] = {};
	int ret = 0,tmp = 0;
	for (int i = 0; i < s.size(); i++) {
		if (ch[s[i]]) {
			while (tmp<i && ch[s[i]]) {
				ch[s[tmp]] --;
				tmp ++;
			} 
		}
		ret = ret > i - tmp+1 ? ret : i - tmp + 1;
		ch[s[i]] ++;
	}
	return ret; 
}