class Solution:
	# @return a string
	def convert(self, s, nRows):
		if (nRows == 1):
			return s
		strs = [""] * nRows
		r = 0
		down = True
		for ch in s:
			strs[r] += ch
			if (down):
				r = r + 1
				if (r == nRows - 1):
					down = False
			else:
				r = r - 1
				if (r == 0):
					down = True
		ret = ""
		for str in strs:
			ret = ret + str
		return ret