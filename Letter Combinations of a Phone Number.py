class Solution:
	def comb(self, head, digits, ret):
		if (len(digits) == 0):
			ret.append(head)
			return
		first = digits[0]
		digits = digits[1:]
		if (first == '2'):
			self.comb(head + 'a', digits, ret)
			self.comb(head + 'b', digits, ret)
			self.comb(head + 'c', digits, ret)
		elif (first == '3'):
			self.comb(head + 'd', digits, ret)
			self.comb(head + 'e', digits, ret)
			self.comb(head + 'f', digits, ret)
		elif (first == '4'):
			self.comb(head + 'g', digits, ret)
			self.comb(head + 'h', digits, ret)
			self.comb(head + 'i', digits, ret)
		elif (first == '5'):
			self.comb(head + 'j', digits, ret)
			self.comb(head + 'k', digits, ret)
			self.comb(head + 'l', digits, ret)
		elif (first == '6'):
			self.comb(head + 'm', digits, ret)
			self.comb(head + 'n', digits, ret)
			self.comb(head + 'o', digits, ret)
		elif (first == '7'):
			self.comb(head + 'p', digits, ret)
			self.comb(head + 'q', digits, ret)
			self.comb(head + 'r', digits, ret)
			self.comb(head + 's', digits, ret)
		elif (first == '8'):
			self.comb(head + 't', digits, ret)
			self.comb(head + 'u', digits, ret)
			self.comb(head + 'v', digits, ret)
		elif (first == '9'):
			self.comb(head + 'w', digits, ret)
			self.comb(head + 'x', digits, ret)
			self.comb(head + 'y', digits, ret)
			self.comb(head + 'z', digits, ret)
	# @return a list of strings, [s1, s2]
	def letterCombinations(self, digits):
		ret = []
		self.comb("", digits, ret)
		return ret
		