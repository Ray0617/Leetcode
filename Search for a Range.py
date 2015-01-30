class Solution:
	def searchFirstGreater(self, A, target):
		# A: sorted
		upper = len(A) # > target
		lower = -1	 # <= target
		while (upper - lower > 1):
			index = (upper + lower) / 2
			if (A[index] > target):
				upper = index
			else:
				lower = index
		return upper
			
	# @param A, a list of integers
	# @param target, an integer to be searched
	# @return a list of length 2, [index1, index2]
	def searchRange(self, A, target):
		start = self.searchFirstGreater(A, target - 1)
		if (start >= len(A)):
			return [-1, -1]
		end = self.searchFirstGreater(A, target) - 1
		if (end < start):
			return [-1, -1]
		return [start, end]