class Solution:
	# @param num, a list of integer
	# @return a list of integer
	def nextPermutation(self, num):
		for i in range(len(num)-1, 0, -1):
			if (num[i-1] < num[i]):
				for j in range(len(num)-1, i-1, -1):
					if (num[j] > num[i-1]):
						temp = num[i-1]
						num[i-1] = num[j]
						num[j] = temp
						return num[0:i] + sorted(num[i:])
		return sorted(num)
