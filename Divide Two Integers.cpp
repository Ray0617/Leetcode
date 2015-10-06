class Solution {
public:
    int divide(int dividend, int divisor) {
        // assert(divisor != 0)
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool minus = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        unsigned long long udividend = abs((long long)dividend);
        unsigned long long udivisor = abs((long long)divisor);
        unsigned int result = 0;
        unsigned long long times = 1;
        
        while (udividend >= udivisor) {
            while (2 * udivisor <= udividend) {
                udivisor *= 2;
                times *= 2;
            }
            result += times;
            udividend -= udivisor;
            while (udivisor > udividend) {
                udivisor /= 2;
                times /= 2;
            }
            if (times == 0)
                break;
        }
        if (minus)
            return (int)(-result);
        else
            return (int)result;
    }
};

