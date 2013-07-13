
class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }

        int minus = n < 0;
        n = abs(n);

        if (n == 1) {
            return minus ? 1/x : x;
        }
        int mod = n % 2;
        double res = pow(x, n/2);
        res *= res;
        if (mod == 1) {
            res *= x;
        }

        return minus ? 1/res : res;
    }
};
