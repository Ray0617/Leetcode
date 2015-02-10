class Solution:
	# @param A a list of integers
	# @return an integer
	def removeDuplicates(self, A):
		w = 0
		count = {}
		for r in xrange(len(A)):
			if (not count.has_key(A[r])):
				count[A[r]] = 0
			if (count[A[r]] == 2):
				continue
			count[A[r]] += 1
			A[w] = A[r]
			w += 1
		return w