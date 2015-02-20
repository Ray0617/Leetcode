/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    static final Comparator<Interval> ComparatorInterval = new Comparator<Interval>() {
        public int compare(Interval i1, Interval i2) {
            return i1.start - i2.start;
        }
    };
    public List<Interval> merge(List<Interval> intervals) {
    	if (intervals.isEmpty())
    		return intervals;
        Collections.sort(intervals, ComparatorInterval);
        List<Interval> result = new ArrayList<Interval>();
        Interval interval = new Interval(intervals.get(0).start, intervals.get(0).end);
        for (Interval iter : intervals) {
            if (iter.start <= interval.end) {
                interval.end = Math.max(interval.end, iter.end);
            }
            else {
                result.add(new Interval(interval.start, interval.end));
                interval.start = iter.start;
                interval.end = iter.end;
            }
        }
        result.add(interval);
        return result;
    }
}