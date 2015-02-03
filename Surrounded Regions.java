public class Solution {
    public void solve(char[][] board) {
        int M = board.length;
        if (M == 0)
            return;
        int N = board[0].length;
        boolean dirty = true;
        while (dirty) {
            dirty = false;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == 'O' && (i==0 || j==0 || i==M-1 || j==N-1
                        || board[i-1][j]=='R' || board[i+1][j]=='R' || board[i][j-1]=='R' || board[i][j+1]=='R')) {
                        board[i][j] = 'R';
                        dirty = true;
                    }
                }
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'R')
                    board[i][j] = 'O';
            }
        }
    }
}