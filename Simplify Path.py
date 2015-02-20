class Solution:
	# @param path, a string
	# @return a string
	def simplifyPath(self, path):
		dirs = path.split("/")
		result = []
		for dir in dirs:
			if (dir == "." or dir == ""):
				continue
			elif (dir == ".."):
				if (result):
					result.pop()
			else:
				result.append(dir)
		str = ""
		for dir in result:
			str += "/" + dir
		if (str == ""):
			return "/"
		return str