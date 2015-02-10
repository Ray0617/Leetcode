class Solution {
public:
    int removeDuplicates(int A[], int n) {
        map<int, int> count;
        int w = 0;
        for (int r = 0; r < n; r++) {
            if (count.find(A[r]) == count.end())
                count[A[r]] = 0;
            if (count[A[r]] != 2) {
                A[w++] = A[r];
                count[A[r]]++;
            }
        }
        return w;
    }
};