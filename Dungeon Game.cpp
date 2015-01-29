class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int> > minHPbeforeStepIn = dungeon;
        for (int r = M-1; r >= 0; r--) {
            for (int c = N-1; c >= 0; c--) {
                int right = INT_MAX;
                if (c < N - 1)
                    right = minHPbeforeStepIn[r][c+1];
                int bottom = INT_MAX;
                if (r < M - 1)
                    bottom = minHPbeforeStepIn[r+1][c];
 				if (r == M-1 && c == N-1)
				{
					right = bottom = 1;	// destination
				}
				// minHP >= 1 && (minHP + dungeon >= right || minHP + dungeon >= bottom)
                minHPbeforeStepIn[r][c] = max(1, min(right, bottom) - dungeon[r][c]);
            }
        }
        return minHPbeforeStepIn[0][0];
    }
};
