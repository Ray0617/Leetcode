class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		if (obstacleGrid[0][0] == 1)
			return 0;
		if (obstacleGrid.back().back() == 1)
			return 0;
		int m = (int)obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> paths(n);
		paths[0] = 1;
		for (int c = 1; c < n; c++) {
			if (obstacleGrid[0][c] == 0) {
				paths[c] = 1;
			} else {
				break;
			}
		}
		for (int r = 1; r < m; r++) {
		    if (obstacleGrid[r][0])
		        paths[0] = 0;
			for (int c = 1; c < n; c++) {
			    if (obstacleGrid[r][c])
			        paths[c] = 0;
			    else
				    paths[c] += paths[c-1];
			}
		}
		return paths.back();
	}
};


