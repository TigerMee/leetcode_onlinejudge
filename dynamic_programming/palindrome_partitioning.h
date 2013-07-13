#ifndef _PALINDRAME_H_
#define _PALINDROME_H_

#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result;
        if (s.length() == 0) {
            return result;
        }

        vector<list<int> > ir;
        get_palindrome(ir, s, 0);

        for (int i = 0; i < ir.size(); i++) {
            result.push_back(vector<string>());
            vector<string> &v = result.back();

            list<int>::iterator it = ir[i].begin();

            ++it;
            v.push_back(string(s, 0, *it + 1));
            int start = *it + 1;
            ++it;

            for (; it != ir[i].end(); ++it) {
                v.push_back(string(s, start, *it + 1 - start));
                start = *it + 1;
            }
        }

        return result;
    }

    void get_palindrome(vector<list<int> > &vv, const string &s, size_t begin) {
        if (s.length() == 0 || begin >= s.length()) {
            return;
        }

        for (int end = begin; end < s.length(); end++) {
            if (is_palindrome(s, begin, end)) {
                get_palindrome(vv, s, end + 1);
                if (end + 1 >= s.length()) {
                    vv.push_back(list<int>());
                    list<int> &l = vv.back();
                    l.push_front(end);
                } else if (!vv.empty()) {
                    for (int i = 0; i < vv.size(); i++) {
                        if (vv[i].front() != -1 && vv[i].front() > end) {
                            vv[i].push_front(end);
                        }
                    }
                }

                if (begin == 0) {
                    for (int i = 0; i < vv.size(); i++) {
                        if (vv[i].front() != -1) {
                            vv[i].push_front(-1);
                        }
                    }
                }
            }
        }

        return;
    }

    bool is_palindrome(const string &s, size_t begin, size_t end) {
        while (end > begin) {
            if (s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};

#endif // _PALINDRAME_H_
