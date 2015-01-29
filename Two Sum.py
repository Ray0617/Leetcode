class Solution:
	# @return a tuple, (index1, index2)
	def twoSum(self, num, target):
		cache = dict()
		for i in xrange(len(num)):
			if (cache.has_key(target - num[i])):
				return [cache[target - num[i]]+1, i+1]
			cache[num[i]] = i
				