class Solution {
public:
    int trailingZeroes(int n) {
        //5, 10, 15, 20, 25(2), 30, ..., 125(3), ...
        int ret = 0;
        while (n >= 5)
        {
            ret += n / 5;
            n /= 5;
        }
        return ret;
    }
};