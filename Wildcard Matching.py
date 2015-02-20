class Solution:
	# @param s, an input string
	# @param p, a pattern string
	# @return a boolean
	def isMatch(self, s, p):
		si = 0
		pi = 0
		sm = -1
		pm = -1
		while (si < len(s)):
			if (pi < len(p) and (s[si] == p[pi] or p[pi] == '?')):
				si += 1
				pi += 1
			elif (pi < len(p) and p[pi] == '*'):
				pi += 1
				pm = pi
				sm = si
			elif (pm != -1):
				sm += 1
				pi = pm
				si = sm
			else:
				return False
		for ch in p[pi:]:
			if (ch != '*'):
				return False
		return True