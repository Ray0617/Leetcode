class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int m = (int)grid.size();
		int n = (int)grid[0].size();
		vector<int> sum(n);
		sum[0] = grid[0][0];
		for (int i = 1; i < n; i++)
			sum[i] = sum[i-1] + grid[0][i];
		for (int r = 1; r < m; r++) {
			sum[0] += grid[r][0];
			for (int c = 1; c < n; c++) {
				sum[c] = grid[r][c] + min(sum[c], sum[c-1]);
			}
		}
		return sum.back();
	}
};

