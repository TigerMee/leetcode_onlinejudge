
#include "common.h"

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

