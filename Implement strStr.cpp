class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == 0 || needle == 0)
            return 0;
        
        int len = strlen(needle);
        char* pch = haystack;
        char* pend = pch + strlen(haystack);
        while (pch + len <= pend)
        {
            if (strncmp(pch, needle, len) == 0)
                return pch;
            pch++;
        }
        return 0;
    }
};