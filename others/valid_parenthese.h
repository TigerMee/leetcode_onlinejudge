

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        char begin[] = { '(', '{', '[' };
        char end[] = { ')', '}', ']' };

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < sizeof(begin)/sizeof(begin[0]); j++) {
                if (s[i] == begin[j]) {
                    st.push(s[i]);
                    break;
                } else if (s[i] == end[j]) {
                    if (st.empty() || st.top() != begin[j]) {
                        return false;
                    } else {
                        st.pop();
                    }
                }
            }
        }
        return st.empty();
    }
};
