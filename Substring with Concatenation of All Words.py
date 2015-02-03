class Solution:
	def check(self, S, L):
		wordLen = len(L[0])
		strLen = wordLen * len(L)
		test = {}
		for i in xrange(len(L)):
			if (not L[i] in test):
				test[L[i]] = 1
			else:
				test[L[i]] = test[L[i]] + 1
		for i in range(0, strLen, wordLen):
			sub = S[i:(i+wordLen)]
			if (not sub in test):
				return False
			test[sub] = test[sub] - 1
			if (test[sub] < 0):
				return False
		return True
	# @param S, a string
	# @param L, a list of string
	# @return a list of integer
	def findSubstring(self, S, L):
		ret = []
		wordLen = len(L[0])
		strLen = wordLen * len(L)
		for i in xrange(len(S)):
			if (i + strLen > len(S)):
				break;
			if (self.check(S[i:(i+strLen)], L)):
				ret.append(i)
		return ret