class Solution:
	# @param words, a list of strings
	# @param L, an integer
	# @return a list of strings
	def fullJustify(self, words, L):
		result = []
		index = 0
		start = 0
		end = 0
		totalLength = 0
		while (index < len(words)):
			if (totalLength == 0 or totalLength + len(words[index]) + (end + 1 - start) - 1 <= L):
				totalLength += len(words[index])
				index += 1
				end += 1
				continue
			# output a line
			line = words[start]
			if (end - start > 1):
				space = (L - totalLength) / (end - start - 1)
				more = (L - totalLength) % (end - start - 1)
				for i in range(start+1, end):
					line += ' ' * space
					if (more > 0):
						line += ' '
						more -= 1
					line += words[i]
			while (len(line) < L):
				line = line + ' '
			result.append(line)
			start = end
			totalLength = 0
		line = words[start]
		for i in range(start+1, len(words)):
			line += ' ' + words[i]
		while (len(line) < L):
			line = line + ' '
		result.append(line)
		return result