class Solution:
	# @return a string
	def countAndSay(self, n):
		result = "1"
		for loop in xrange(n-1):
			temp = result
			result = ""
			digit = temp[0]
			count = 0
			for ch in temp:
				if (digit == ch):
					count += 1
				else:
					result += str(count)
					result += digit
					digit = ch
					count = 1
			result += str(count)
			result += digit
		return result