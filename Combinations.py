class Solution:
	cache = dict()
	# @return a list of lists of integers
	def combine(self, n, k):
		# return [combine(n-1, k), [combine(n-1,k-1),n] ]
		if (not self.cache.has_key((n,k))):
			if (k == 0):
				self.cache[(n,k)] = [[]]
			elif (n == 0):
				self.cache[(n,k)] = [[]]
			elif (n == k):
				self.cache[(n,k)] = [range(1,n+1)]
			else:
				c1 = copy.deepcopy(self.combine(n-1, k-1))
				for i in xrange(len(c1)):
					c1[i].append(n)
				c1.extend(self.combine(n-1,k))
				self.cache[(n,k)] = c1
		return self.cache[(n,k)]