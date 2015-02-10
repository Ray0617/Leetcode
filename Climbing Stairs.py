class Solution:
	# @param n, an integer
	# @return an integer
	def climbStairs(self, n):
		if (n == 0):
			return 0
		if (n == 1):
			return 1
		if (n == 2):
			return 2
		f1 = 1
		f2 = 2
		for i in range(3, n+1):
			f3 = f1 + f2
			f1 = f2
			f2 = f3
		return f2