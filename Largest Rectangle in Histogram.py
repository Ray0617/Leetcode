class Solution:
	# @param height, a list of integer
	# @return an integer
	def largestRectangleArea(self, height):
		ascend = []
		height.append(0)
		maxArea = 0
		for i in xrange(len(height)):
			if (i > 0 and height[i] < height[i-1]):
				while (len(ascend) > 0):
					h = height[ascend[-1]]
					if (h < height[i]):
						break;
					del ascend[-1]
					right = i
					if (len(ascend) == 0):
						left = 0
					else:
						left = ascend[-1] + 1
					area = h * (right - left)
					if (area > maxArea):
						maxArea = area
			ascend.append(i)
		return maxArea