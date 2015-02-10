class Solution:
	# @return a boolean
	def isValid(self, s):
		par = []
		for ch in s:
			if (ch == '(' or ch == '[' or ch == '{'):
				par.append(ch)
			elif (ch == ')' or ch == ']' or ch == '}'):
				if (not par):
					return False
				prev = par.pop()
				if (prev == '(' and ch == ')' or prev == '[' and ch == ']' or prev == '{' and ch == '}'):
					continue
				return False
		return (not par)