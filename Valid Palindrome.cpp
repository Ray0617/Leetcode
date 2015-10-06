class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            if (!isalnum(s[head])) {
                head++;
                continue;
            }
            if (!isalnum(s[tail])) {
                tail--;
                continue;
            }
            if (tolower(s[head]) != tolower(s[tail]))
                return false;
            head++;
            tail--;
        }
        return true;
    }
};

