class Solution:
	# @param a list of integers
	# @return an integer
	def removeDuplicates(self, A):
		if (len(A) == 0):
			return 0
		w = 0
		last = A[0] - 1
		for r in xrange(len(A)):
			if (A[r] != last):
				A[w] = A[r]
				last = A[r]
				w = w + 1
		return w
		