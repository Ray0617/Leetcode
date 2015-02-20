class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left;
        int right = -1;
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // left
                left.push(i);
            }
            else {
                // right
                if (left.empty()) {
                    right = i;
                }
                else {
                    left.pop();
                    int start = left.empty()?right:left.top();
                    int len = i - start;
                    if (len > max_len)
                        max_len = len;
                }
            }
        }
        return max_len;
    }
};