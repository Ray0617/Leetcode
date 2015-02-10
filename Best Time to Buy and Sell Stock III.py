class Solution:
	# @param prices, a list of integer
	# @return an integer
	def maxProfit(self, prices):
		if (not prices):
			return 0
		cash = [0] * len(prices)
		for transactions in xrange(2):
			for i in xrange(len(cash)):
				cash[i] -= prices[i]
				if (i > 0 and cash[i-1] > cash[i]):
					cash[i] = cash[i-1]
			for i in xrange(len(cash)):
				cash[i] += prices[i]
				if (i > 0 and cash[i-1] > cash[i]):
					cash[i] = cash[i-1]
		return cash[-1]