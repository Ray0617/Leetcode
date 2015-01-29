class Solution:
	# @param dungeon, a list of lists of integers
	# @return a integer
	def calculateMinimumHP(self, dungeon):
		M = len(dungeon)
		N = len(dungeon[0])
		minimumHPBeforeStepIn = [ [0]*N ] * M
		for row in range(M-1, -1, -1):
			for col in range(N-1, -1, -1):
				right = 9999999
				if (row < M - 1):
					right = minimumHPBeforeStepIn[row + 1][col]
				bottom = 9999999
				if (col < N - 1):
					bottom = minimumHPBeforeStepIn[row][col + 1]
				if (row == M - 1 and col == N - 1):
					right = bottom = 1
				# minHP > 0; minHP + dungeon > min(right, bottom)
				minimumHPBeforeStepIn[row][col] = max(1, min(right, bottom) - dungeon[row][col])
		return minimumHPBeforeStepIn[0][0]