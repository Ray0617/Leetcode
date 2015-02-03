public class Solution {
    public String longestPalindrome(String s) {
        int N = s.length();
        int maxlen = 0;
        int arg_i = 0;
        int arg_j = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                int len = 0;
                while (i - len >= 0 && i + j + len < N) {
                    if (s.charAt(i-len) == s.charAt(i+j+len)) {
                        if (2*len+j+1 > maxlen) {
                            maxlen = 2 * len + j + 1;
                            arg_i = i - len;
                            arg_j = i + j + len;
                        }
                    }
                    else
                        break;
                    len++;
                }
            }
        }
        return s.substring(arg_i, arg_j + 1);
    }
}