class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        int maxlen = 1;
        int arg_i = 0;
        int arg_j = 0;
        for (int i = 0; i < N; i++) {
            //center at i
            int len = 0;
            while (i - len >= 0 && i + len < N) {
                if (s[i-len] == s[i+len]) {
                    if (2 * len + 1 > maxlen) {
                        maxlen = 2 * len + 1;
                        arg_i = i - len;
                        arg_j = i + len;
                    }
                }
                else
                    break;
                len++;
            }
            
            //center at i and i+1
            if (i < N-1 && s[i] == s[i+1]) {
                len = 0;
                while (i - len >= 0 && i + 1 + len < N) {
                    if (s[i-len] == s[i+1+len]) {
                        if (2 * len + 2 > maxlen) {
                            maxlen = 2 * len + 2;
                            arg_i = i - len;
                            arg_j = i + 1 + len;
                        }
                    }
                    else
                        break;
                    len++;
                }
            }
        }
        return s.substr(arg_i, arg_j - arg_i + 1);
    }
};