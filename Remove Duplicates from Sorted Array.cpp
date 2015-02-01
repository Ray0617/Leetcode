class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int w = 1;
        for (int r = 1; r < n; r++)
        {
            if (A[r] == A[w-1])
                continue;
            else
            {
                A[w++] = A[r];
            }
        }
        return w;
    }
};