class Solution {
public:
    void generateParenthesis(int lefts, int rights, string& str, vector<string>& result) {
        if (lefts == 0 && rights == 0) {
            result.push_back(str);
            return;
        }
        if (lefts > 0) {
            str.push_back('(');
            generateParenthesis(lefts - 1, rights, str, result);
            str.pop_back();
        }
        if (lefts < rights) {
            str.push_back(')');
            generateParenthesis(lefts, rights - 1, str, result);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        generateParenthesis(n, n, str, result);
        return result;
    }
};

