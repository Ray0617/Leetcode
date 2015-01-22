public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        int i = 0;
        int j = 0;
        int count = 0;
        int med = ( A.length + B.length - 1 ) / 2;
        boolean odd = (((A.length + B.length) % 2) > 0);
        int median1 = 0;
        while (true) {
            int value;
            if (i >= A.length) {
                value = B[j++];
            } else if (j >= B.length) {
                value = A[i++];
            } else if (A[i] < B[j]) {
                value = A[i++];
            } else {
                value = B[j++];
            }
            if (count == med) {
                if (odd)
                    return value;
                else
                    median1 = value;
            } else if (count == med+1) {
                return (double)(value + median1) / 2;
            }
            count++;
        }
    }
}
