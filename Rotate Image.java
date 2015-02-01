public class Solution {
    public void rotate(int[][] matrix) {
        // (x, y) -> (y, W-x) -> (W-x, H-y) -> (H-y, x) -> (x, y)
        int N = matrix.length;
        for (int x = 0; x < (N+1)/2; x++) {
            for (int y = 0; y < N/2; y++) {
                int temp = matrix[x][y];
                matrix[x][y] = matrix[N-y-1][x];
                matrix[N-y-1][x] = matrix[N-1-x][N-1-y];
                matrix[N-1-x][N-1-y] = matrix[y][N-1-x];
                matrix[y][N-1-x] = temp;
            }
        }
    }
}