class Solution:
	# @return a float
	def findMedianSortedArrays(self, A, B):
		i = 0
		j = 0
		count = 0
		med = (len(A)+len(B)-1)//2
		odd = (len(A)+len(B))%2
		while (True):
			if (i >= len(A)):
				value = B[j]
				j = j + 1
			elif (j >= len(B)):
				value = A[i]
				i = i + 1
			elif (A[i] < B[j]):
				value = A[i]
				i = i + 1
			else:
				value = B[j]
				j = j + 1
			if (count == med):
				if (odd):
					return value
				else:
					temp = value
			elif (count == med + 1):
				return float(temp + value) / 2
			count = count + 1
