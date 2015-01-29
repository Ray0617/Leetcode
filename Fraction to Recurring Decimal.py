class Solution:
	# @return a string
	def fractionToDecimal(self, numerator, denominator):
		if (numerator == 0):
			return "0"
		ret = ""
		if ((numerator > 0 and denominator < 0) or (numerator < 0 and denominator > 0)):
			ret = "-"
		numerator = abs(numerator)
		denominator = abs(denominator)
		quotient = numerator / denominator
		ret = ret + str(quotient)
		reminder = numerator % denominator
		if (reminder == 0):
			return ret
		ret = ret + '.'
		cache = dict()
		digits = []
		index = -1
		while (reminder > 0):
			numerator = reminder
			if (cache.has_key(numerator)):
				index = cache[numerator]
				break
			cache[numerator] = len(digits)
			numerator = numerator * 10
			quotient = numerator / denominator
			reminder = numerator % denominator
			digits.append(quotient)
		for i in xrange(len(digits)):
			if (i == index):
				ret = ret + '('
			ret = ret + str(digits[i])
		if (index != -1):
			ret = ret + ')'
		return ret
