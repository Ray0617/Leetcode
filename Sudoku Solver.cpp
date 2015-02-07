
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        bool rowFlag[9][9] = {0};
        bool colFlag[9][9] = {0};
        bool blockFlag[3][3][9] = {0};
        struct Step {
            Step(int r, int c, int n):row(r),col(c),num(n){}
            int row;
            int col;
            int num;
        };
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    rowFlag[r][num] = true;
                    colFlag[c][num] = true;
                    blockFlag[r/3][c/3][num] = true;
                }
            }
        }
        vector<Step> path;
        bool hasEmpty = true;
		Step lastStep = Step(0, 0, 0);
        while (hasEmpty) {
            hasEmpty = false;
            bool found = false;
            for (int r = lastStep.row; r < 9; r++) {
                for (int c = lastStep.col; c < 9; c++) {
                    if (board[r][c] == '.') {
                        hasEmpty = true;
                        for (int n = lastStep.num; n < 9; n++) {
                            if (!rowFlag[r][n] && !colFlag[c][n] && !blockFlag[r/3][c/3][n]) {
                                board[r][c] = '1' + n;
                                rowFlag[r][n] = true;
                                colFlag[c][n] = true;
                                blockFlag[r/3][c/3][n] = true;
                                path.push_back(Step(r, c, n));
                                lastStep = Step(0, 0, 0);
                                found = true;
                                break;
                            }
                        }
			            break;
                    }
                }
                if (hasEmpty)
                    break;
            }
            if (found)
                continue;
            if (!hasEmpty)
                break;
            lastStep = path.back();
            path.pop_back();
            rowFlag[lastStep.row][lastStep.num] = false;
            colFlag[lastStep.col][lastStep.num] = false;
            blockFlag[lastStep.row/3][lastStep.col/3][lastStep.num] = false;
            board[lastStep.row][lastStep.col] = '.';
			lastStep.num++;
        }
    }
};