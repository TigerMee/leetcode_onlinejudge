
#include "common.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// @return true: i1 is less than i2
bool interval_less_than(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool interval_less_than(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() == 0) {
            return vector<Interval>();
        }

        vector<Interval> res;

        sort(intervals.begin(), intervals.end(), interval_less_than);

        Interval cur(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= cur.end) {
                cur.end = max(cur.end, intervals[i].end);
            } else {
                res.push_back(cur);
                cur.start = intervals[i].start;
                cur.end = intervals[i].end;
            }
        }
        if (cur.start != INT_MIN) {
            res.push_back(cur);
        }
        return res;
    }
};
