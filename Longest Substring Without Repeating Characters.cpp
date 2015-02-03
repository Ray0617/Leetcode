
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool appear[256] = {0};
        int maxlen = 0;
        int i = 0;
        int j = 0;
        int N = s.length();
        while (j < N) {
            if (appear[(unsigned)s[j]]) {
                while (i < j && s[i] != s[j]) {
					appear[(unsigned)s[i]] = false;
                    i++;
                }
				i++;
				j++;
            }
            else {
                appear[(unsigned)s[j]] = true;
                j++;
                if (j - i > maxlen)
                    maxlen = j - i;
            }
        }
        return maxlen;
    }
};