class Solution:
	def find(self, tail, candidates, target, result):
		if (target == 0):
			result.append(copy.copy(tail))
		
		filter = []
		sum = 0
		for i in candidates:
			if (i > target):
				break;
			filter.append(i)
			sum = sum + i
		if (sum < target):
			return
		if (len(filter) == 0):
			return
		
		biggest = filter[len(filter) - 1]
		filter.pop()
		# select biggest one
		tail.insert(0, biggest)
		self.find(tail, filter, target - biggest, result)
		tail.pop(0)
		while (len(filter) > 0 and filter[-1] == biggest):
			filter.pop()
		self.find(tail, filter, target, result)
		
	# @param candidates, a list of integers
	# @param target, integer
	# @return a list of lists of integers
	def combinationSum2(self, candidates, target):
		result = []
		candidates.sort()
		self.find([], candidates, target, result)
		return result
