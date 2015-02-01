public class Solution {
    public int removeDuplicates(int[] A) {
        int write = 0;
        int last = Integer.MAX_VALUE;
        for (int read = 0; read < A.length; read++) {
            if (A[read] == last) {
                continue;
            }                
            else {
                A[write] = A[read];
                last = A[read];
                write++;
            }
        }
        return write;
    }
}