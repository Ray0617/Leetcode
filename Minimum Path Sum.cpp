class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
            
        vector<vector<int> > score = grid;
        int max_m = grid.size();
        int max_n = grid[0].size();
        for (int sum = 0; sum <= max_m + max_n - 2; ++sum)
        {
            for (int m = 0; m <= min(sum, max_m - 1); ++m)
            {
                int n = sum - m;
                if (n < 0 || n >= max_n)
                    continue;
                if (m == 0 && n == 0)
                {}
                else if (m > 0 && n == 0)
                    score[m][n] += score[m-1][n];
                else if (n > 0 && m == 0)
                    score[m][n] += score[m][n-1];
                else
                    score[m][n] += min(score[m-1][n], score[m][n-1]);
            }
        }
        return score[max_m-1][max_n-1];
    }
};