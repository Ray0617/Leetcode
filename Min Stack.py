class MinStack:
	def __init__(self):
		self.value = []
		self.min = []
	# @param x, an integer
	# @return an integer
	def push(self, x):
		self.value.append(x)
		if (not self.min or x <= self.min[-1]):
			self.min.append(x)

	# @return nothing
	def pop(self):
		val = self.value.pop()
		if (self.min[-1] == val):
			self.min.pop()

	# @return an integer
	def top(self):
		return self.value[-1]

	# @return an integer
	def getMin(self):
		return self.min[-1]
		