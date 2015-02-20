class Solution:
	# @param version1, a string
	# @param version2, a string
	# @return an integer
	def compareVersion(self, version1, version2):
		nums1 = version1.split('.')
		nums2 = version2.split('.')
		for i in xrange(max(len(nums1), len(nums2))):
			ver1 = 0
			if (i < len(nums1)):
				ver1 = int(nums1[i])
			ver2 = 0
			if (i < len(nums2)):
				ver2 = int(nums2[i])
			if (ver1 < ver2):
				return -1
			if (ver1 > ver2):
				return 1
		return 0