class Solution:
	def divideAndConquer(self, sol, num, result):
		if (not num):
			result.append(copy.copy(sol))
			return
		for i in xrange(len(num)):
			n = num[i]
			num.pop(i)
			sol.append(n)
			self.divideAndConquer(sol, num, result)
			sol.pop()
			num.insert(i, n)
	# @param num, a list of integer
	# @return a list of lists of integers
	def permute(self, num):
		sol = []
		result = []
		self.divideAndConquer(sol, num, result)
		return result