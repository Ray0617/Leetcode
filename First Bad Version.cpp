// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (!isBadVersion(n))
            return n + 1;
        if (isBadVersion(1))
            return 1;
        long long lower = 1;
        long long upper = n;
        while (lower < upper - 1) {
            long long mid = (lower + upper) >> 1;
            if (isBadVersion((int)mid))
                upper = mid;
            else
                lower = mid;
        }
        return upper;
    }
};

