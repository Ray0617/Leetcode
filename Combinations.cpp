class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> c;
        for (int i = 1; i <= k; i++)
            c.push_back(i);
        ret.push_back(c);
        
        while (1)
        {
            // next c
            int i = k - 1;
            while (i < k)
            {
                if (c[i] < n)
                {
                    c[i]++;
                    if (i == k-1)
                        break;
                    else
                    {
                        i++;
                        c[i] = c[i-1];
                    }
                }
                else
                {
                    i--;
                    if (i < 0)
                        return ret;
                }
            }
            
            ret.push_back(c);
        }
    }
};