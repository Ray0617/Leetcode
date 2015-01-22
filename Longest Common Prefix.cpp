class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.empty())
            return prefix;
        
        int index = 0;
        while (true)
        {
            if (index >= strs[0].size())
                return prefix;
            char ch = strs[0][index];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (index >= strs[i].length() || ch != strs[i][index])
                    return prefix;
            }
            prefix.push_back(ch);
            index++;
        }
        return prefix;
    }
};