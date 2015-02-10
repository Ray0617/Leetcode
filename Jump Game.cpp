class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0)
            return false;
        int farest = 0;
        for (int i = 0; i < n; i++) {
            if (i > farest)
                return false;
            farest = max(i + A[i], farest);
            if (farest >= n - 1)
                break;
        }
        return true;
    }
};