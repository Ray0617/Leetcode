class Solution:
	# @param board, a 9x9 2D array
	# Solve the Sudoku by modifying the input board in-place.
	# Do not return any value.
	def solveSudoku(self, board):
		rowFlag = [[False] * 9 for i in xrange(9)]
		colFlag = [[False] * 9 for i in xrange(9)]
		blkFlag = [[[False] * 9 for i in xrange(3)] for j in xrange(3)]
		for r in xrange(9):
			for c in xrange(9):
				if (board[r][c] != '.'):
					n = ord(board[r][c]) - ord('1')
					rowFlag[r][n] = True
					colFlag[c][n] = True
					blkFlag[r/3][c/3][n] = True
		
		path = []
		cont = True
		step = [0, 0, 0]
		while (cont):
			cont = False
			found = False
			for r in range(step[0], 9):
				for c in range(step[1], 9):
					if (board[r][c] == '.'):
						cont = True
						for n in range(step[2], 9):
							if (not rowFlag[r][n] and not colFlag[c][n] and not blkFlag[r/3][c/3][n]):
								rowFlag[r][n] = True
								colFlag[c][n] = True
								blkFlag[r/3][c/3][n] = True
								board[r][c] = chr(ord('1') + n)
								path.append([r, c, n])
								step = [0, 0, 0]
								found = True
								break
						break
				if (cont):
					break
			if (not cont):
				break
			if (found):
				continue
			step = path.pop()
			board[step[0]][step[1]] = '.'
			rowFlag[step[0]][step[2]] = False
			colFlag[step[1]][step[2]] = False
			blkFlag[step[0]/3][step[1]/3][step[2]] = False
			step[2] = step[2] + 1
		