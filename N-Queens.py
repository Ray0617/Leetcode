class Solution:
	def isConflict(self, row, col, n, sol):
		qr = 0
		for qc in sol:
			if (qr == row or qc == col or row + col == qr + qc or row - col == qr - qc):
				return True
			qr = qr + 1
		return False
	# @return a list of lists of string
	def solveNQueens(self, n):
		if (n == 0):
			return []
		ret = []
		sol = []
		last = 0
		while (True):
			row = len(sol)
			if (row == n):
				dot = "." * n
				ans = []
				for i in xrange(n):
					ans.append(dot[0:sol[i]] + 'Q' + dot[(sol[i]+1):n])
				ret.append(ans)
			if (row < n):
				# try to put queen in next row
				found = False
				for col in range(last, n):
					if (not self.isConflict(row, col, n, sol)):
						# find a legal postion to put the new queen
						sol.append(col)
						last = 0
						found = True
						break
				if (found):
					continue
			# not found, try to pop out the last queen
			if (len(sol) == 0):
				break
			last = sol.pop() + 1
		return ret