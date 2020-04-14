#include "../Solution.h"

//#69 sqrt(x)
int Solution::mySqrt(int x) {
	long long l = 0, r = x , m = (l+r+1)/2;
	while (l<r) { 
		if (m * m == x) return m;
		if (m * m < x) {
			l = m;
		}
		else { // m*m > x
			r = m - 1;
		}
		m = (l + r + 1) / 2;
	}
	return (int)m;
}