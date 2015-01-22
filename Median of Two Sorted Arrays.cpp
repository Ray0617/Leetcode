class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        assert(m+n>0);
        int i = 0;
        int j = 0;
        int count = 0;
        int med = (m + n - 1) / 2;
        bool odd = (m + n) % 2;
        int median1;
        while (i < m || j < n) {
            int value;
            if (i >= m) {
                value = B[j++];
            } else if (j >= n) {
                value = A[i++];
            } else if (A[i] < B[j]) {
                value = A[i++]; 
            } else {
                value = B[j++];
            }
            if (count == med ) {
                if (odd)
                    return value;
                else
                    median1 = value;
            }
            else if (count == med + 1 && !odd) {
                return (double)(value + median1)/2;
            }
            count++;
        }
    }
};
