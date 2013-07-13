

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool negative = (x < 0);
        if (negative) {
            x = -x;
        }

        int res = 0;

        while (x > 0) {
            res *= 10;
            res += (x % 10);
            x /= 10;
        }

        return negative ? -res : res;
    }
};
