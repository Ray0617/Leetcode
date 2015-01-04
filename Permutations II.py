class Solution:
	def conquer(self, head, num, perms):
		if (len(num) == 0):
			perms.append(copy.copy(head))
			return
		used = []
		
		for i in copy.copy(num):
			if (i in used):
				continue
			used.append(i)
			head.append(i)
			num.remove(i)
			self.conquer(head, num, perms)
			head.pop(len(head)-1)
			num.append(i)
	# @param num, a list of integer
	# @return a list of lists of integers
	def permuteUnique(self, num):
		perms = []
		head = []
		self.conquer(head, num, perms)
		return perms;