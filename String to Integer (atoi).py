class Solution:
	# @return an integer
	def fit_in_range(self, x):
		if (x > 2147483647):
			return 2147483647
		elif (x < -2147483648):
			return -2147483648
		else:
			return x
	def atoi(self, str):
		ret = 0
		sign = +1
		status = 0  # not number; might be sign symbol or white space
		for ch in str:
			if (status == 0):
				if (ch == ' ' or ch == '\t'):
					continue
				if (ch == '+'):
					status = 1
					continue
				if (ch == '-'):
					status = 1
					sign = -1
					continue
				if (ch >= '0' and ch <= '9'):
					status = 1
				else:
					return 0
			if (status == 1):
				if (ch >= '0' and ch <= '9'):
					ret = ret * 10 + ord(ch) - ord('0')
				else:
					return self.fit_in_range(sign * ret)
		return self.fit_in_range(sign * ret)
		