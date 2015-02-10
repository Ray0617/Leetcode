class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        vector<int> cash(prices.size());
        // have bought the stock, max cash at time i
        for (int i = 0; i < prices.size(); i++) {
            cash[i] -= prices[i];
            if (i > 0 && cash[i-1] > cash[i])
                cash[i] = cash[i-1];
        }
        // have sold the stock, max cash at time i
        for (int i = 0; i < prices.size(); i++) {
            cash[i] += prices[i];
            if (i > 0 && cash[i-1] > cash[i])
                cash[i] = cash[i-1];
        }
        return cash.back();
    }
};