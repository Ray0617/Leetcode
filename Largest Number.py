def significantDigitComparatorStr(str1, str2):
	l1 = len(str1)
	l2 = len(str2)
	l = min(l1, l2)
	for i in xrange(l):
		if (str1[i] > str2[i]):
			return 1
		elif (str1[i] < str2[i]):
			return -1
	if (l1 == l2):
		return 0
	if (l1 < l2):
		return significantDigitComparatorStr(str1, str2[l1:])
	else:
		return significantDigitComparatorStr(str1[l2:], str2)
def significantDigitComparator(n1, n2):
	return significantDigitComparatorStr(str(n1), str(n2))
class Solution:
	# @param num, a list of integers
	# @return a string
	def largestNumber(self, num):
		num.sort(cmp=significantDigitComparator)
		if (not num or num[-1] == 0):
			return "0"
		result = ""
		for n in num:
			result = str(n) + result
		return result