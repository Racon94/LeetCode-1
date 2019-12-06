#include "Solution.h"

//#6 Zigzag conversion
string Solution::convert(string s, int numRows) {
	if (numRows == 1) return s; // without zig zag return the origin string ;  
	string ret = s;
	int cnt = 0 , tmp;
	for (int row = 0; row < numRows; row++) {
		if (row == 0 || row == numRows - 1) {
			tmp = 0;
			while (tmp * (2*numRows-2) + row < s.size()) {
				ret[cnt] = s[tmp * (2 * numRows - 2) + row]; 
				tmp++;
				cnt++;
			}
		}
		else {
			tmp = 0;
			while ((tmp+1) * (2 * numRows - 2) -row < s.size()) {
				ret[cnt] = s[tmp * (2 * numRows - 2) + row];
				cnt++;
				ret[cnt] = s[(tmp+1) * (2 * numRows - 2) - row];
				tmp++;
				cnt++;
			}
			if (tmp * (2 * numRows - 2) + row < s.size()) {
				ret[cnt] = s[tmp * (2 * numRows - 2) + row];
				tmp++;
				cnt++;
			}
		}
	}
	return ret; 
}
/*
0123456789 £¬ 3 -->
0 4 8  s[i % (3*2-2) == +-0]
13579  s[i % (3*2-2) == +-1]
2 6    s[i % (3*2-2) == +-2]


0123456789 £¬ 4 -->
0  6   s[i % (2*4-2) == +-0]
1 57   s[i % (2*4-2) == +-1]
24 8   s[i % (2*4-2) == +-2]
3  9   s[i % (2*4-2) == +-3]
*/