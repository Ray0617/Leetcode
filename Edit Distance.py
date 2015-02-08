class Solution:
	# @return an integer
	def minDistance(self, word1, word2):
		distance = [[0]*(len(word2)+1) for i in xrange(len(word1)+1)]
		distance[0] = range(0, len(word2)+1)
		for i in xrange(len(word1)+1):
			distance[i][0] = i
		for i in range(1, len(word1)+1):
			for j in range(1, len(word2)+1):
				needReplace = 1
				if (word1[i-1] == word2[j-1]):
					needReplace = 0	
				distance[i][j] = min(distance[i-1][j]+1, distance[i][j-1]+1, distance[i-1][j-1]+needReplace);
		return distance[len(word1)][len(word2)]
