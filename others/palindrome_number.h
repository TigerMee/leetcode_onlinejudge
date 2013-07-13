
#include <math.h>

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }

        int lowest = x % 10;
        int heighest = x / 10;
        int heighest_cnt = 1;

        while (heighest > 9) {
            heighest /= 10;
            heighest_cnt++;
        }

        if (heighest != lowest) {
            return false;
        }

        double d = pow(10.0, heighest_cnt);
        int i = heighest * (int)d;

        return isPalindrome((x - i) % 10);
    }
};
