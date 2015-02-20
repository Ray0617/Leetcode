from sets import Set
class Solution:
	# @param num, a list of integer
	# @return an integer
	def longestConsecutive(self, num):
		cache = Set(num)
		checked = Set()
		max_length = 0
		for n in num:
			if (n in checked):
				continue
			length = 1
			p = n + 1
			while (p in cache):
				checked.add(p)
				p += 1
				length += 1
			m = n - 1
			while (m in cache):
				checked.add(m)
				m -= 1
				length += 1
			if (length > max_length):
				max_length = length
		return max_lengthmax_length