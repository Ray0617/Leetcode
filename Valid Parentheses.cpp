class Solution {
public:
    bool isValid(string s) {
        vector<char> parentheses;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parentheses.push_back(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (parentheses.empty())
                    return false;
                char prev = parentheses.back();
                parentheses.pop_back();
                if (prev == '(' && s[i] == ')' || prev == '[' && s[i] == ']' || prev == '{' && s[i] == '}')
                    continue;
                return false;
            }
        }
        return parentheses.empty();
    }
};