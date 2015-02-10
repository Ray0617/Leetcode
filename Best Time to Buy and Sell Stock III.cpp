class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N == 0)
            return 0;
        vector<int> cash(N);
        for (int transactions = 0; transactions < 2; transactions++) {
            for (int i = 0; i < N; i++) {
                cash[i] -= prices[i];   // buy at time i
                if (i > 0 && cash[i-1] > cash[i])
                    cash[i] = cash[i-1];    // buy before could minimize the cost
            }
            for (int i = 0; i < N; i++) {
                cash[i] += prices[i];   // sell at time i
                if (i > 0 && cash[i-1] > cash[i])
                    cash[i] = cash[i-1];    // sell before could maxmize the profit
            }
        }
        return cash[N-1];
    }
};