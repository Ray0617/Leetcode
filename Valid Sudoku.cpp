class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0};
        bool col[9][9] = {0};
        bool block[3][3][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if (row[i][num])
                    return false;
                row[i][num] = true;
                if (col[j][num])
                    return false;
                col[j][num] = true;
                if (block[i/3][j/3][num])
                    return false;
                block[i/3][j/3][num] = true;
            }
        }
        return true;
    }
};

