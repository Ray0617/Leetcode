class Solution:
	# @return an integer
	def lengthOfLongestSubstring(self, s):
		longest = 0
		start = 0
		end = 0
		test = {}
		while (end < len(s)):
			if (not s[end] in test):
				test[s[end]] = True
			else:
				while (s[start] != s[end]):
					del test[s[start]]
					start = start + 1
				start = start + 1
			end = end + 1
			if (end - start > longest):
				longest = end - start
		return longest