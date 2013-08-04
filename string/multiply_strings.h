
#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = num1.length();
        int l2 = num2.length();

        if (l1 == 0 || l2 == 0
            || num1[0] == '0' || num2[0] == '0') {
            return "0";
        }

        int *arr = new int[l1 + l2];
        memset(arr, 0, sizeof(int) * (l1 + l2));

        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                arr[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
            }
        }

        for (int i = l1+l2-1; i >= 0; i--) {
            if (arr[i] >= 10) {
                arr[i-1] += arr[i] / 10;
                arr[i] %= 10;
            }
        }

        string res;
        res.reserve(l1+l2);
        for (int i = 0; i < l1+l2; i++) {
            if (arr[i] == 0 && res.empty()) {
                continue;
            }
            res.push_back('0'+arr[i]);
        }
        return res;
    }
};

class Solution2 {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1.length() == 0 || num2.length() == 0
            || num1 == "0" || num2 == "0") {
            return "0";
        }

        // minus
        bool minus = false;
        if (num1[0] == '-') {
            minus = !minus;
            num1 = num1.substr(1);
        }
        if (num2[0] == '-') {
            minus = !minus;
            num2 = num2.substr(1);
        }

        string res;
        for (int i = num2.length()-1; i >= 0; i--) {
            string tmp = multiply(num1, num2[i]);
            tmp.append((num2.length()-1 - i), '0');
            res = add(res, tmp);
        }

        return res;
    }

    string multiply(const string &num, char c) {
        string res;
        if (num.length() == 0 || c == '0') {
            return res;
        }

        int carry = 0;
        int multi = 0;
        for (int i = num.length()-1; i >= 0; i--) {
            multi = (num[i]-'0') * (c-'0') + carry;
            carry = multi / 10;
            multi = multi % 10;
            res.insert(0, 1, '0'+multi);
        }
        if (carry != 0) {
            res.insert(0, 1, '0'+carry);
        }
        return res;
    }

    string add(const string &num1, const string &num2) {
        if (num1.empty()) {
            return num2;
        }
        if (num2.empty()) {
            return num1;
        }
        string res;
        int carry = 0;
        int cur = 0;

        int pos1 = num1.length()-1;
        int pos2 = num2.length()-1;

        while (pos1 >= 0 || pos2 >= 0) {
            if (pos1 < 0) {
                cur = (num2[pos2]-'0') + carry;
                pos2--;
            } else if (pos2 < 0) {
                cur = (num1[pos1]-'0') + carry;
                pos1--;
            } else {
                cur = (num1[pos1]-'0') + (num2[pos2]-'0') + carry;
                pos1--;
                pos2--;
            }
            carry = cur / 10;
            cur = cur % 10;
            res.insert(0, 1, '0'+cur);
        }
        if (carry > 0) {
            res.insert(0, 1, '0'+carry);
        }

        return res;
    }
};
