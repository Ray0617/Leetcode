class Solution:
	def isMatch(self, s, p):
		M = len(s)
		N = len(p)
		match = [[False] * (N+1) for i in xrange(M+1)]
		match[0][0] = True 
		for i in xrange(M+1):
			for j in xrange(N+1):
				if (not match[i][j]):
					continue
				star = (j < N-1 and p[j+1] == '*')
				if (not star and i < M and j < N and (s[i] == p[j] or p[j] == '.')):
					# the case s = [match_part]x and p = [match_part]x
					match[i+1][j+1] = True
				if (star):
					# the case s = [match_part] and p = [match_part]x*
					match[i][j+2] = True
					k = i
					while (k < M and (s[k] == p[j] or p[j] == '.')):
						match[k+1][j+2] = True
						k = k + 1
		return match[M][N]
