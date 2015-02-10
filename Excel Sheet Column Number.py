class Solution:
	# @param s, a string
	# @return an integer
	def titleToNumber(self, s):
		num = 0
		for ch in s:
			num *= 26
			num += ord(ch) - ord('A') + 1
		return num