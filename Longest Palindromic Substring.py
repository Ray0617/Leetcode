class Solution:
	# @return a string
	def longestPalindrome(self, s):
		N = len(s)
		maxsz = 0
		argi = 0
		argj = 0
		# zigzag = N/2, N/2-1, N/2+1, N/2-2, N/2+2...
		zigzag = [N/2]
		for i in range(1,N/2+1):
			zigzag.append(N/2-i)
			zigzag.append(N/2+i)
		if (zigzag[len(zigzag)-1] == N):
			zigzag = zigzag[:-1]
			
		for i in zigzag:
			# maxlen would be 2*i+2 or 2*(N-1-i)+1
			if (2*i+2 < maxsz):
				continue
			if (2*(N-i-1)+1 < maxsz):
				continue
			for j in [0,1]:
				sz = 0
				while (i-sz >= 0 and i+j+sz < N):
					if (s[i-sz] == s[i+j+sz]):
						if (2*sz+j > maxsz):
							maxsz = 2*sz+j
							argi = i-sz
							argj = i+j+sz
					else:
						break
					sz = sz + 1
		return s[argi:argj+1]