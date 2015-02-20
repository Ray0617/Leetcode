# Definition for an interval.
# class Interval:
#	 def __init__(self, s=0, e=0):
#		 self.start = s
#		 self.end = e
def compareInterval(x, y):
	return x.start - y.start
class Solution:
	# @param intervals, a list of Interval
	# @return a list of Interval
	def merge(self, intervals):
		if (not intervals):
			return intervals
		intervals = sorted(intervals, cmp=compareInterval)
		result = []
		interval = intervals[0]
		for iter in intervals:
			if (iter.start <= interval.end):
				interval.end = max(iter.end, interval.end)
			else:
				result.append(Interval(interval.start, interval.end))
				interval.start = iter.start
				interval.end = iter.end
		result.append(interval)
		return result
		