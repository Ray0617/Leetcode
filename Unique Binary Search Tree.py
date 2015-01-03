class Solution:
	# @return an integer
	def numTrees(self, n):
		if (len(self.caches) == 0):
			self.caches = [1, 1]
		if (n < len(self.caches)):
			return self.caches[n]
		for i in xrange(len(self.caches), n+1):
			num = 0
			for left in xrange(i):
				right = i - 1 - left;
				num += self.caches[left] * self.caches[right]
			self.caches.append(num)
		return self.caches[n]
	caches = []