public class Solution {
    public int firstMissingPositive(int[] A) {
        for (int i = 0; i < A.length; i++) {
            while (A[i] >= 1 && A[i] <= A.length) {
                // swap A[A[i] - 1] with A[i]
                int temp = A[i];
                if (temp == A[temp-1])
                    break;
                A[i] = A[temp - 1];
                A[temp - 1] = temp;
            }
        }
        for (int i = 0; i < A.length; i++) {
            if (A[i] != i+1)
                return i+1;
        }
        return A.length + 1;
    }
}