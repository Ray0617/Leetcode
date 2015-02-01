class Solution:
	# @param grid, a list of lists of integers
	# @return an integer
	def minPathSum(self, grid):
		BIG_VAL = 99999999
		M = len(grid)
		N = len(grid[0])
		sum = [[0]*N]*M
		for r in xrange(M):
			for c in xrange(N):
				left = BIG_VAL
				if (c > 0):
					left = sum[r][c-1]
				top = BIG_VAL
				if (r > 0):
					top = sum[r-1][c]
				if (r == 0 and c == 0):
					left = 0
				sum[r][c] = min(left, top) + grid[r][c]
		return sum[M-1][N-1]