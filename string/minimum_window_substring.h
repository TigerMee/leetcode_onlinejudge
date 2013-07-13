
#include "common.h"

// 自己写的优化算法
class Solution {
public:
    string minWindow(string S, string T) {
        const size_t CHAR_COUNT = 128;
        int text[CHAR_COUNT];
        int pattern[CHAR_COUNT];

        for (size_t i = 0; i < CHAR_COUNT; i++)
            text[i] = pattern[i] = 0;
        for (size_t i = 0; i < T.length(); i++)
            pattern[T[i]]++;

        int min_begin = -1, min_end = -1;
        int begin = 0, end = 0;

        text[S[end]]++;
        while (end < S.length()) {
            if (greaterOrEqual(text, pattern, CHAR_COUNT)) {
                if (begin == 0 || (end - begin) < (min_end - min_begin)) {
                    min_begin = begin;
                    min_end = end;
                }
                text[S[begin]]--;
                begin++;
            } else {
                end++;
                text[S[end]]++;
            }
        }

        if (min_begin != -1)
            return S.substr(min_begin, min_end - min_begin + 1);
        else
            return string();
    }

    bool greaterOrEqual(int *a1, int *a2, size_t size) {
        for (size_t i = 0; i < size; i++) {
            if (a1[i] < a2[i])
                return false;
        }
        return true;
    }
};



// 网上找到的优化解法
class Solution2 {
public:
bool notLarger(int x[128], int y[128]) {
    bool result = true;
    for(int i = 0; i < 128; i++) {
        if(x[i] <= y[i]) {
            result = result && true;
        }
        else {
            result = false;
        }
    }

    return result;
}

string minWindow(string S, string T) {
    int pattern[128];
    int text[128];
    bool signal = false;

    for(int i = 0; i < 128; i++) {
        pattern[i] = 0;
        text[i] = 0;
    }

    for(int i = 0; i < T.size(); i++){
        pattern[T[i]]++;
    }

    int start = 0, end = 0;
    int minStart = 0, minEnd = 0, minLength = S.size();

    text[S[end]]++;

    while(end < S.size()) {
        if(notLarger(pattern, text)) {
            if(minLength >= end - start + 1) {
                signal = true;
                minLength = end - start + 1;
                minStart = start;
                minEnd = end;
            }
            if(start < end) {
                text[S[start]]--;
                start++;
            }
            else {
                end++;
                text[S[end]]++;
            }
        }
        else {
            end++;
            if(end < S.size()) {
                text[S[end]]++;
            }
        }
    }
    if(signal) {
        string result(S, minStart, minEnd - minStart + 1);
        return result;
    }
    else {
        return "";
    }
}
};

// 低效的算法
class Solution3 {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.length() == 0 || T.length() == 0) {
            return string();
        }

        // char position in S of T
        size_t pos_size = T.length();
        int *pos = new int[pos_size];
        clear(pos, pos_size);

        // char count of T
        int char_count[128];
        for (int i = 0; i < 128; i++)
            char_count[i] = 0;
        for (size_t i = 0; i < T.length(); i++) {
            char_count[T[i]]++;
        }

        int min_b = -1;
        int min_e = -1;

        for (size_t i = 0; i < S.length(); i++) {
            // 先查找T中还没有出现的字符
            for (size_t k = 0; k < T.length(); k++) {
                if (S[i] == T[k]) {
                    if (pos[k] != -1 && char_count[T[k]] != 0)
                        continue;

                    if (pos[k] == -1)
                        char_count[T[k]]--;
                    pos[k] = i;

                    int new_b = 0, new_e = 0;
                    if (isValid(pos, pos_size, new_b, new_e)) {
                        if (min_b == -1 || (new_e - new_b) < (min_e - min_b)) {
                            min_b = new_b;
                            min_e = new_e;
                        }

                        // clear min
                        int min_pos = 0;
                        for (size_t ii = 1; ii < pos_size; ii++) {
                            if (pos[ii] < pos[min_pos])
                                min_pos = ii;
                        }
                        pos[min_pos] = -1;
                        char_count[T[min_pos]]++;
                    }
                    break;
                }
            }
        }

        if (min_b == -1)
            return string();
        return S.substr(min_b, min_e - min_b + 1);
    }

    void clear(int *arr, size_t size) {
        size_t i = 0;
        while (i++ < size) {
            *arr = -1;
            arr++;
        }
    }

    bool isValid(const int * arr, size_t size,
                int &begin, int &end) {
        begin = -1;
        end = -1;
        for (size_t i = 0; i < size; i++) {
            if (arr[i] == -1)
                return false;
            if (arr[i] < begin || begin == -1)
                begin = arr[i];
            if (arr[i] > end || end == -1)
                end = arr[i];
        }
        return true;
    }
};
