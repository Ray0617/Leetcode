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
private:
    static bool compareInterval(Interval& i1, Interval& i2) {
        return i1.start < i2.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.empty())
			return intervals;
        sort(intervals.begin(), intervals.end(), compareInterval);
        int w = 0;
        for (int r = 0; r < intervals.size(); r++) {
            if (intervals[w].end >= intervals[r].start) {
				intervals[w].end = max(intervals[r].end, intervals[w].end);
            }
            else {
                w++;
				intervals[w] = intervals[r];
            }
        }
        intervals.resize(w + 1);
        return intervals;
    }
};