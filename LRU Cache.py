class LRUCache:

	# @param capacity, an integer
	def __init__(self, capacity):
		self.cache = {}
		self.capacity = capacity
		self.order = []

	def touch(self, key):
		if (key in self.order):
			self.order.remove(key)
		self.order.insert(0, key)

	# @return an integer
	def get(self, key):
		if (not key in self.order):
			return -1
		self.touch(key)
		return self.cache[self.order[0]]

	# @param key, an integer
	# @param value, an integer
	# @return nothing
	def set(self, key, value):
		if (not key in self.cache):
			if (len(self.cache) == self.capacity):			
				del self.cache[self.order.pop()]
		self.touch(key)
		self.cache[key] = value
