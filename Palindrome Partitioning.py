class Solution:
	def isPalindrome(self, str):
		i = 0
		j = len(str) - 1
		while (i < j):
			if (str[i] != str[j]):
				return False
			i = i + 1
			j = j - 1
		return True
	def doPartition(self, str, substrs, result):
		for i in range(1, len(str)+1):
			substr = str[0:i]
			if (not self.isPalindrome(substr)):
				continue
			substrs.append(substr)
			if (i == len(str)):
				result.append(copy.copy(substrs))
			else:
				self.doPartition(str[i:], substrs, result)
			substrs.pop()
	
	# @param s, a string
	# @return a list of lists of string
	def partition(self, s):
		substrs = []
		result = []
		self.doPartition(s, substrs, result)
		return result