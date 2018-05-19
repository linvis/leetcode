/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool resort (Interval i,Interval j) { 
    return (i.start < j.start); 
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int i = 0;
        int len = intervals.size();
        std::sort(intervals.begin(), intervals.end(), resort);
        while(i < len - 1) {
            if (((intervals[i].end >= intervals[i + 1].start) && (intervals[i].end <= intervals[i + 1].end)) ||
                    ((intervals[i + 1].end >= intervals[i].start) && (intervals[i + 1].end <= intervals[i].end))) {
                intervals[i].end = max(intervals[i].end, intervals[i + 1].end);
                intervals[i].start = min(intervals[i].start, intervals[i + 1].start);
                intervals.erase(intervals.begin() + i + 1);
                len = intervals.size();
                continue;
            } else {
                i++;
            }
        }
        return intervals;
    }
};
