
#include "common.h"

// solution using unordered_set
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) return (int)num.size();

        int n = num.size();
        int max_con = 0;
        unordered_set<int> s;

        for (int i = 0; i < num.size(); i++) {
            s.insert(num[i]);
        }

        for (int i = 0; i < num.size(); i++) {
            if (s.find(num[i]) != s.end()) {
                int min = num[i]-1;
                while (s.find(min) != s.end()) {
                    s.erase(min);
                    min--;
                }
                int maximum = num[i]+1;
                while (s.find(maximum) != s.end()) {
                    s.erase(maximum);
                    maximum++;
                }
                min++;
                maximum--;
                max_con = max(max_con, maximum-min+1);

                s.erase(num[i]);
            }
        }
        return max_con;
    }
};

// solution using map, much slower
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::map<int, int> pairs;

        for (vector<int>::const_iterator it = num.begin(); it != num.end(); ++it) {
            bool find = false;
            for (std::map<int, int>::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) {
                if (*it == pit->first-1) {
                    pairs[*it] = pit->second;
                    pairs.erase(pit);
                    find = true;
                } else if (*it >= pit->first && *it <= pit->second) {
                    find = true;
                } else if (*it == pit->second+1) {
                    pit->second = *it;
                    find = true;

                    // merge next pair if possible
                    ++pit;
                    if (pit == pairs.end())
                        break;
                    if (*it >= pit->first-1) {
                        int end = pit->second;
                        pit--;
                        pit->second = end;

                        pit++;
                        pairs.erase(pit);
                    }
                } else if (pit->first > *it)
                    break;
                if (find) {
                    break;
                }
            }
            if (!find)
                pairs[*it] = *it;
        }

        int max_interval = 0;
        for (std::map<int, int>::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) {
            if ((pit->second - pit->first + 1) > max_interval)
                max_interval = pit->second - pit->first + 1;
        }
        return max_interval;


    }
};
