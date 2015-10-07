class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1)
            return s;
        
        vector<string> rows(nRows);
        
        int r = 0;
        int dir = +1;
        for (int i = 0; i < s.length(); i++)
        {
            rows[r].push_back(s[i]);
            if (dir > 0)
            {
                r++;
                if (r == nRows - 1)
                    dir = -1;
            }
            else
            {
                r--;
                if (r == 0)
                    dir = +1;
            }
        }
        string ret;
        for (int i = 0; i < nRows; i++)
            ret += rows[i];
        return ret;
    }
};
