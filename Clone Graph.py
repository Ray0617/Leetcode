# Definition for a undirected graph node
# class UndirectedGraphNode:
#	 def __init__(self, x):
#		 self.label = x
#		 self.neighbors = []

class Solution:
	def cloneGraphWithCache(self, node, cache):
		if (not node):
			return None
		if (not cache.has_key(node.label)):
			cloned = UndirectedGraphNode(node.label)
			cache[node.label] = cloned
			for neighbor in node.neighbors:
				cloned.neighbors.append(self.cloneGraphWithCache(neighbor, cache))
		return cache[node.label]
	# @param node, a undirected graph node
	# @return a undirected graph node
	def cloneGraph(self, node):
		cache = {}
		return self.cloneGraphWithCache(node, cache)
