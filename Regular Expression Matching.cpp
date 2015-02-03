class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == 0 && *p == 0)
            return true;
        if (*p == 0)
            return false;
        if (*(p+1) == '*') 
            return ((*s == *p || *p == '.') && (*s != 0) && isMatch(s+1, p)) || isMatch(s, p+2); 
        if (*s != 0 && (*s == *p || *p == '.'))
            return isMatch(s+1, p+1);
        return false;
    }
};