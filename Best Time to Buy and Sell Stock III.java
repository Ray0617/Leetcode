public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0)
            return 0;
        int[] cash = new int [prices.length];
        for (int transactions = 0; transactions < 2; transactions++) {
            for (int i = 0; i < cash.length; i++) {
                cash[i] -= prices[i];
                if (i > 0 && cash[i-1] > cash[i])
                    cash[i] = cash[i-1];
            }
            
            for (int i = 0; i < cash.length; i++) {
                cash[i] += prices[i];
                if (i > 0 && cash[i-1] > cash[i])
                    cash[i] = cash[i-1];
            }
        }
        return cash[cash.length - 1];
    }
}