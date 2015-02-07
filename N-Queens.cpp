
class Solution {
public:
    void addQueen(vector<vector<int> >& flag, int r, int c, int val) {
        int n = (int)flag.size();
        for (int i = 0; i < n; i++) {
            flag[r][i] += val;
            flag[i][c] += val;
			if (r+i<n && c+i<n)
				flag[r+i][c+i] += val;
			if (r-i>=0 && c-i>=0)
				flag[r-i][c-i] += val;
			if (r+i<n && c-i>=0)
				flag[r+i][c-i] += val;
			if (r-i>=0 && c+i<n)
				flag[r-i][c+i] += val;
        }
        flag[r][c] -= 5 * val;
    }
    void putQueen(vector<vector<int> >& flag, int r, int c) {
        return addQueen(flag, r, c, +1);
    }
    void popQueen(vector<vector<int> >& flag, int r, int c) {
        return addQueen(flag, r, c, -1);
    }
    string strQueen(int k, int n) {
        string emptyStr;
        for (int i = 0; i < n; i++)
            emptyStr.push_back('.');
        string ret = emptyStr;
        ret[k] = 'Q';
        return ret;
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n == 0) {
            return ret;
        }
        vector<vector<int> > flag;
        flag.resize(n);
        for (int i = 0; i < n; i++)
            flag[i].resize(n);
        vector<string> sol;
        int last = 0;
        while (true) {
            int row = sol.size();
            if (row < n) {
                // try to put next line
                bool found = false;
                for (int i = last; i < n; i++) {
                    if (flag[row][i] == 0) {
                        found = true;
                        putQueen(flag, row, i);
                        sol.push_back(strQueen(i, n));
                        last = 0;
                        if (row + 1 == n)
                            ret.push_back(sol);
                        break;
                    }
                }
                if (found)
                    continue;
            }
            
            // try move current Queen to next column
			if (sol.empty())
				break;
            string curQueen = sol.back();
            sol.pop_back();
            int q = (int)curQueen.find("Q");
            popQueen(flag, sol.size(), q);
            last = q + 1;
        }
        return ret;
    }
};