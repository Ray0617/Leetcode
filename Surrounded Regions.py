class Solution:
	# @param board, a 2D array
	# Capture all regions by modifying the input board in-place.
	# Do not return any value.
	def solve(self, board):
		M = len(board)
		if (M == 0):
			return
		N = len(board[0])
		dirty = True
		while (dirty):
			dirty = False
			for i in xrange(M):
				for j in xrange(N):
					if (board[i][j] == 'O' and 
						(i == 0 or i == M - 1 or j == 0 or j == N - 1
							or i > 0 and board[i-1][j] == 'v' or j > 0 and board[i][j-1] == 'v'
							or i < M - 1 and board[i+1][j] == 'v' or j < N - 1 and board[i][j+1] == 'v')
						):
						board[i][j] = 'v'
						dirty = True
		for i in xrange(M):
			for j in xrange(N):
				if (board[i][j] == 'O'):
					board[i][j] = 'X'
				elif (board[i][j] == 'v'):
					board[i][j] = 'O'
		
							
					