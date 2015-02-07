public class Solution {
    private void setQueen(int[][] flag, int val, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            flag[row][i] += val;
            flag[i][col] += val;
            if (row + i < n && col + i < n)
                flag[row + i][col + i] += val;
            if (row - i >= 0 && col - i >= 0)
                flag[row - i][col - i] += val;
            if (row + i < n && col - i >= 0)
                flag[row + i][col - i] += val;
            if (row - i >= 0 && col + i < n)
                flag[row - i][col + i] += val;
        }
        flag[row][col] -= 5 * val;
    }
    public List<String[]> solveNQueens(int n) {
        List<String[]> ret = new ArrayList<String[]>();
        if (n == 0)
            return ret;
        String[] sample = new String[n];
        for (int i = 0; i < n; i++) {
        	sample[i] = "";
            for (int j = 0; j < n; j++) {
                if (i == j)
                    sample[i] += "Q";
                else
                    sample[i] += ".";
            }
        }
        List<Integer> sol = new ArrayList<Integer>();
        int[][] flag = new int[n][n];
        int last = 0;
        while (true) {
            int row = sol.size();
            if (row < n) {
                // try to put queen in the next row
                boolean found = false;
                for (int i = last; i < n; i++) {
                    if (flag[row][i] == 0) {
                        // put the queen at row, i
                        setQueen(flag, +1, row, i, n);
                        sol.add(i);
                        last = 0;
                        found = true;
                    }
                }
                if (found)
                    continue;
            }
            if (row == n) {
                String[] ans = new String[n];
                for (int i = 0; i < n; i++)
                    ans[i] = sample[sol.get(i)];
                ret.add(ans);
            }
            // try to put queen in the next column
            // just pull it out and keep the last position in record
            if (sol.isEmpty())
                break;
            int r = sol.size() - 1;
            int c = sol.get(sol.size() - 1);
            setQueen(flag, -1, r, c, n);
            sol.remove(sol.size() - 1);
            last = c + 1;
        }
        return ret;
    }
}