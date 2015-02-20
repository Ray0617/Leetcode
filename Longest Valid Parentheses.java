public class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> left = new Stack<Integer>();
        int right = -1;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left.push(i);
            }
            else {
                if (left.empty()) {
                    right = i;
                }
                else {
                    left.pop();
                    int start = left.empty()?right:left.peek();
                    int len = i - start;
                    if (len > maxLen)
                        maxLen = len;
                }
            }
        }
        return maxLen;
    }
}