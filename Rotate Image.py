class Solution:
	# @param matrix, a list of lists of integers
	# @return a list of lists of integers
	def rotate(self, matrix):
		# (x, y) -> (y, W-x) -> (W-x, H-y) -> (H-y, x) -> (x, y)
		N = len(matrix)
		for x in xrange((N+1)/2):
			for y in xrange(N/2):
				temp = matrix[x][y]
				matrix[x][y] = matrix[N-1-y][x]
				matrix[N-1-y][x] = matrix[N-1-x][N-1-y]
				matrix[N-1-x][N-1-y] = matrix[y][N-1-x]
				matrix[y][N-1-x] = temp
		return matrix