
#include "common.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int begin = -1;
        int end = -1;

        const char *ptr = s;
        int pos = 0;
        bool inChar = false;

        while (*ptr != '\0') {
            if (*ptr != ' ') {
                if (!inChar) {
                    begin = pos;
                    inChar = true;
                }
            }
            if (*ptr == ' ' && inChar) {
                end = pos;
                inChar = false;
            }
            pos++;
            ptr++;
        }
        if (inChar) {
            end = pos;
        }


        return end - begin;
    }
};
