public class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int M = dungeon.length;
        int N = dungeon[0].length;
        int[][] minimumHPBeforeStepIn = new int [M][N];
        for (int r = M - 1; r >= 0; r--) {
            for (int c = N - 1; c >= 0; c--) {
                int right = Integer.MAX_VALUE;
                if (r < M - 1)
                    right = minimumHPBeforeStepIn[r + 1][c];
                int bottom = Integer.MAX_VALUE;
                if (c < N - 1)
                    bottom = minimumHPBeforeStepIn[r][c + 1];
                if (r == M - 1 && c == N - 1)
                    right = 1;
                // minHP + dungeon = min(minHP_right, minHP_bottom); minHP > 0
                minimumHPBeforeStepIn[r][c] = Math.max(1, Math.min(right, bottom) - dungeon[r][c]);
            }
        }
        return minimumHPBeforeStepIn[0][0];
    }
}
