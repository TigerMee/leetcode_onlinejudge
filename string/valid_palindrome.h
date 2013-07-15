#ifndef _VALID_PALINDROME_H_
#define _VALID_PALINDROME_H

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t len = s.length();
        if (len == 0) {
            return true;
        }

        int head = 0;
        int tail = len - 1;

        while (tail >= head) {
            char chead = s[head];
            char ctail = s[tail];

            if (!isalpha(chead) && !isdigit(chead)) {
                head++;
                continue;
            }

            if (!isalpha(ctail) && !isdigit(ctail)) {
                tail--;
                continue;
            }

            if (tolower(chead) == tolower(ctail)) {
                head++;
                tail--;
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};

#endif
