public class Solution {
    class Step {
        public Step(int r, int c, int n) {
            row = r;
            col = c;
            num = n;
        }
        public void reset() {
        	row = col = num = 0;
        }
        public int row;
        public int col;
        public int num;
    }
    public void solveSudoku(char[][] board) {
        boolean[][] rowFlag = new boolean[9][9];
        boolean[][] colFlag = new boolean[9][9];
        boolean[][][] blockFlag = new boolean[3][3][9];
        for (int r = 0; r < board.length; r++) {
            for (int c = 0; c < board[0].length; c++) {
                if (board[r][c] != '.') {
                    int n = board[r][c] - '1';
                    rowFlag[r][n] = true;
                    colFlag[c][n] = true;
                    blockFlag[r/3][c/3][n] = true;
                }
            }
        }

        List<Step> path = new ArrayList<Step>();
        Step lastStep = new Step(0, 0, 0);
        while (true) {
            boolean hasEmpty = false;
            boolean found = false;
            for (int r = lastStep.row; r < board.length; r++) {
                for (int c = lastStep.col; c < board.length; c++) {
                    if (board[r][c] == '.') {
                        hasEmpty = true;
                        for (int n = lastStep.num; n < 9; n++) {
                            if (!rowFlag[r][n] && !colFlag[c][n] && !blockFlag[r/3][c/3][n]) {
                                rowFlag[r][n] = true;
                                colFlag[c][n] = true;
                                blockFlag[r/3][c/3][n] = true;
                                board[r][c] = (char)('1' + n);
                                path.add(new Step(r, c, n));
                                lastStep.reset();
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

            lastStep = path.get(path.size() - 1);
            path.remove(path.size() - 1);
            board[lastStep.row][lastStep.col] = '.';
            rowFlag[lastStep.row][lastStep.num] = false;
            colFlag[lastStep.col][lastStep.num] = false;
            blockFlag[lastStep.row/3][lastStep.col/3][lastStep.num] = false;
            lastStep.num++;
        }
    }
}