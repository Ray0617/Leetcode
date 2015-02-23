class Solution:
	# @return an integer
	def uniquePaths(self, m, n):
		# ((m-1)+(n-1))! / (m-1)! / (n-1)!
		x = m - 1;
		y = n - 1;
		# (x+y)!/(x!y!)=(x+y)*(x+y-1)*...*(1+y)/x!
		result = 1;
		for i in range(1, x+1):
			result *= (y+i)
			result /= i
		return result	