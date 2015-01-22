class Solution:
	# @param a, a string
	# @param b, a string
	# @return a string
	def addBinary(self, a, b):
		index = 0
		carry = 0
		sum = ""
		while (carry > 0 or index < len(a) or index < len(b)):
			digit = carry
			if (index < len(a) and a[len(a)-1-index] == '1'):
				digit = digit + 1
			if (index < len(b) and b[len(b)-1-index] == '1'):
				digit = digit + 1
			carry = digit // 2
			digit = digit % 2
			if (digit == 1):
				sum = "1" + sum
			else:
				sum = "0" + sum
			index = index + 1
		return sum
