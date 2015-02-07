class Solution:
	# @param A, a list of integers
	# @return an integer
	def firstMissingPositive(self, A):
		for i in xrange(len(A)):
			while (A[i] - 1 >= 0 and A[i] - 1 < len(A)):
				n = A[i]
				# swap A[i] and A[n-1]
				if (n == A[n-1]):
					break;
				tmp = A[i]
				A[i] = A[n-1]
				A[n-1] = tmp
		for i in xrange(len(A)):
			if (A[i] != i+1):
				return i+1
		return len(A)+1