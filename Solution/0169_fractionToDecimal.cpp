#include "../Solution.h"

//166. Fraction to Recurring Decimal
//the repeating is related to b in n*10^t % d = a ... [b], if b repeating,the decimal repeating!!
//the no repeating dicimal is related to the number of 2,5 in denominator 
string Solution::fractionToDecimal(int numerator, int denominator){
	int cnt = 0;
	long long num = numerator, den = denominator;
	string ret = "";
	if (num * den < 0) ret.append("-");
	num = num > 0 ? num : -num; 
	den = den > 0 ? den : -den;
	ret.append(to_string(num / den));
	if (num % den == 0) return ret;
	num = num % den;
	long long nor = 0, tmp = den;
	while (tmp % 2 == 0 || tmp % 5 == 0) {
		nor++;
		if (tmp % 2 == 0)tmp /= 2;
		if (tmp % 5 == 0)tmp /= 5;
	}
	ret.append(".");
	map <long long, int> hash; 
	tmp = 0;
	while (num) {
		tmp++;
		if(tmp >= nor)hash[num] ++;
		if (hash[num] > 1) {
			ret.insert(ret.find('.') + nor + 1, "(");
			ret.append(")");
			return ret;
		}
		ret.append(to_string(num * 10 / den));
		num = num * 10 % den;
	}
	return ret;
}