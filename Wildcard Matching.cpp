class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = 0;
        const char* t = 0;
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
                continue;
            }
            if (*p == '*') {
                star = p;
                t = s;
                p++;
                continue;
            }
            if (star) {
                p = star + 1;
                t++;
                s = t;
                continue;
            }
            return false;
        }
        while (*p == '*')
            p++;
        return *p == 0;
    }
};