class Solution:
	# @param A, a list of integers
	# @return a boolean
	def canJump(self, A):
		farest = 0
		for i in xrange(len(A)):
			if (farest < i):
				return False
			farest = max(farest, i + A[i])
			if (farest >= len(A) - 1):
				return True
		return True