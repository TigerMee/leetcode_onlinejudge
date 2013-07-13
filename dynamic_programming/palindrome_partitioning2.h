#ifndef _PALINDROME2_H_
#define _PALINDROME2_H_

#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > svv = partition(s);
        int min_cut = -1;

        for (int i = 0; i < svv.size(); i++) {
            if (min_cut == -1) {
                min_cut = svv[i].size();
            } else if (svv[i].size() < min_cut) {
                min_cut = svv[i].size();
            }
        }

        return min_cut - 1;
    }

    vector<vector<string> > partition(const string &s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result;
        if (s.length() == 0) {
            return result;
        }

        vector<vector<int> > ir = get_palindrome(s, 0);

        for (int i = 0; i < ir.size(); i++) {
            result.push_back(vector<string>());
            vector<string> &v = result.back();

            v.push_back(string(s, 0, ir[i][0] + 1));
            for (int j = 1; j < ir[i].size(); j++) {
                v.push_back(string(s, ir[i][j - 1] + 1, ir[i][j] - ir[i][j - 1]));
            }
        }

        return result;
    }

    vector<vector<int> > get_palindrome(const string &s, size_t begin) {
        vector<vector<int> > result;

        if (s.length() == 0 || begin >= s.length()) {
            return result;
        }

        for (int end = begin; end < s.length(); end++) {
            if (is_palindrome(s, begin, end)) {
                vector<vector<int> > vv = get_palindrome(s, end + 1);
                if (!vv.empty()) {
                    for (int i = 0; i < vv.size(); i++) {
                        result.push_back(vector<int>());
                        vector<int> &v = result.back();
                        v.push_back(end);
                        for (vector<int>::iterator it = vv[i].begin();
                            it != vv[i].end(); ++it) {
                                v.push_back(*it);
                        }
                    }
                } else if (end + 1 >= s.length()) {
                    result.push_back(vector<int>());
                    vector<int> &v = result.back();
                    v.push_back(end);
                }
            }
        }

        return result;
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

#endif // _PALINDROME2_H_
