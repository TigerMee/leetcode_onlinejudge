
#include "common.h"

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (str == NULL) {
            return 0;
        }

        // skip space charactor
        while (*str == ' ') {
            ++str;
        }

        // negative or not
        bool negative = false;
        if (*str == '-') {
            negative = true;
            str++;
        } else if (*str == '+') {
            str++;
        }

        long long num = 0;
        while (*str != '\0') {
            if (*str >= '0' && *str <= '9') {
                num = num * 10 + (*str-'0');
                str++;
                if (num > INT_MAX) {
                    break;
                }
            } else {
                break;
            }
        }

        // int32: [-2^31, 2^31-1]
        if (negative) {
            return num > INT_MAX ? INT_MIN : -num;
        } else {
            return num > INT_MAX ? INT_MAX : num;
        }
    }
};
