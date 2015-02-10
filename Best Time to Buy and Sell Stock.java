public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0)
            return 0;
        int minPay = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < minPay)
                minPay = prices[i];
            if (prices[i] - minPay > maxProfit)
                maxProfit = prices[i] - minPay;
        }
        return maxProfit;
    }
}