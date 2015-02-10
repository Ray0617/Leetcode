class Solution:
	# @param num, a list of integer
	# @return an integer
	def findPeakElement(self, num):
		left = -1
		right = len(num)
		mid = (left + right) / 2
		while (mid - left > 1 or right - mid > 1):
			if (mid - left > 1):
				leftmid = (left + mid) / 2
				if (num[leftmid] < num[mid]):
					left = leftmid
				else:
					right = mid
					mid = leftmid
			if (right - mid > 1):
				rightmid = (mid + right) / 2
				if (num[rightmid] < num[mid]):
					right = rightmid
				else:
					left = mid
					mid = rightmid
		return s