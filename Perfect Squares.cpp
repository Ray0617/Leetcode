class Solution {
public:
    int numSquares(int n) {
        vector<int> result(n+1);
        result[1] = 1;
        for (int i = 2; i <= n; i++) {
            result[i] = i;
            int sq = sqrt(i);
            for (int s = 1; s <= sq; s++) {
                if (result[i - s * s] + 1 < result[i])
                    result[i] = result[i-s*s] + 1;
            }
        }
        return result[n];
    }
};
