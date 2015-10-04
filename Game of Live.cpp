class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> cloned = board;
        int row = (int)board.size();
        if (row == 0)
            return;
        int col = (int)board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int lives = 0;
                for (int x = i - 1; x <= i+1; x++) {
                    for (int y = j - 1; y <= j+1; y++) {
                        if (x == i && y == j)
                            continue;
                        if (x >= 0 && x < row && y >= 0 && y < col && cloned[x][y])
                            lives++;
                    }
                }
                if (cloned[i][j]) {
                    // live -> dead
                    if (lives < 2 || lives > 3)
                        board[i][j] = 0;
                }
                else {
                    // dead -> live
                    if (lives == 3)
                        board[i][j] = 1;
                }
            }
        }
        
    }
};
