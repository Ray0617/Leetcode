class Solution:
	# @param prices, a list of integer
	# @return an integer
	def maxProfit(self, prices):
		if (not prices):
			return 0
		payment = -prices[0]
		profit = 0
		for price in prices:
			payment = max(payment, -price)
			profit = max(profit, price + payment)
		return profit