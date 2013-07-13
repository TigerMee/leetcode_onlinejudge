
#include "common.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }

        bool inserted = false;
        for (size_t i = 0; i < intervals.size(); i++) {
            const Interval& cur = intervals[i];
            if (cur.end < newInterval.start) res.push_back(cur);
            else if (cur.start <= newInterval.end
                    && cur.end >= newInterval.start) {  // merge
                newInterval.start = min(newInterval.start, cur.start);
                newInterval.end = max(newInterval.end, cur.end);

                int j = i + 1;
                for (; j < intervals.size(); j++) {
                    if (intervals[j].start <= newInterval.end) {
                        newInterval.start = min(newInterval.start, intervals[j].start);
                        newInterval.end = max(newInterval.end, intervals[j].end);
                    } else {
                        break;
                    }
                }
                res.push_back(newInterval);
                inserted = true;
                i = j - 1;
            } else {
                if (!inserted) {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(cur);
            }
        }
        if (!inserted) {
            res.push_back(newInterval);
            inserted = true;
        }
        return res;
    }
};
