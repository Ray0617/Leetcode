class Solution:
	# @return an integer
	def trailingZeroes(self, n):
		zeroes = 0
		while (n >= 5):
			zeroes += n/5
			n /= 5
		return zeroes