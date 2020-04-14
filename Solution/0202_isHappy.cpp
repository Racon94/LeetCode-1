#include "../Solution.h"

bool Solution::isHappy(int n) {
    // cout << n << endl ;
    if (n > 1 && n < 10 && n != 7) return false;
    if (n == 1) return true;
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return isHappy(sum);
}