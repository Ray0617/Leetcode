class Solution:
	def digitToRoman(self, digit, one, five, ten):
		if (digit == 0):
			return ""
		elif (digit == 1):
			return one
		elif (digit == 2):
			return one + one
		elif (digit == 3):
			return one + one + one
		elif (digit == 4):
			return one + five
		elif (digit == 5):
			return five
		elif (digit == 6):
			return five + one
		elif (digit == 7):
			return five + one + one
		elif (digit == 8):
			return five + one + one + one
		elif (digit == 9):
			return one + ten
	# @return a string
	def intToRoman(self, num):
		str = self.digitToRoman(num % 10, 'I', 'V', 'X')
		num /= 10
		str = self.digitToRoman(num % 10, 'X', 'L', 'C') + str
		num /= 10
		str = self.digitToRoman(num % 10, 'C', 'D', 'M') + str
		num /= 10
		return self.digitToRoman(num % 10, 'M', '?', '?') + str
