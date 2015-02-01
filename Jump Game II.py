class Solution:
	# @param A, a list of integers
	# @return an integer
	def jump(self, A):
		step = 0
		start = 0
		end = 1
		while (end < len(A)):
			farest = start
			for i in range(start, end):
				far = i + A[i]
				if (far > farest):
					farest = far
			start = end
			end = farest + 1
			step = step + 1
		return step