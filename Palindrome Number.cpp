class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long tmp = x;
        long long y = 0;
        while (tmp > 0) {
            y *= 10;
            y += tmp % 10;
            tmp /= 10;
        }
        return x == y;
    }
};

