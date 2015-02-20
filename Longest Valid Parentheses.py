class Solution:
	# @param s, a string
	# @return an integer
	def longestValidParentheses(self, s):
		right = -1
		left = []
		max_len = 0
		for i in xrange(len(s)):
			if (s[i] == '('):
				left.append(i)
			else:
				if (left):
					left.pop()
					if (left):
						start = left[-1]
					else:
						start = right
					l = i - start
					if (l > max_len):
						max_len = l
				else:
					right = i
		return max_len