class Solution:
	def divideAndConquer(self, selects, candidates, target, ret):
		if (target == 0):
			ret.append(copy.copy(selects))
			return
		if (not candidates):
			return
		biggest = candidates[-1]
		candidates.pop()
		for numOfBiggest in range(0, target / biggest + 1):
			for i in xrange(numOfBiggest):
				selects.insert(0, biggest)
			target = target - biggest * numOfBiggest
			self.divideAndConquer(selects, candidates, target, ret)
			target = target + biggest * numOfBiggest
			selects = selects[numOfBiggest:]
		candidates.append(biggest)

	# @param candidates, a list of integers
	# @param target, integer
	# @return a list of lists of integers
	def combinationSum(self, candidates, target):
		ret = []
		selects = []
		candidates.sort()
		self.divideAndConquer(selects, candidates, target, ret)
		return ret