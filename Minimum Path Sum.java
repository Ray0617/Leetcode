public class Solution {
    public int minPathSum(int[][] grid) {
        int M = grid.length;
        int N = grid[0].length;
        
        int[][] sum = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int left = Integer.MAX_VALUE;
                if (j > 0)
                    left = sum[i][j-1];
                int top = Integer.MAX_VALUE;
                if (i > 0)
                    top = sum[i-1][j];
                if (i == 0 && j == 0)
                    left = 0;
                sum[i][j] = Math.min(left, top) + grid[i][j];
            }
        }
        return sum[M-1][N-1];
    }
}