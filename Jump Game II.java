public class Solution {
    public int jump(int[] A) {
        int count = 0;
        int start = 0; int end = 1; //range in this step
        while (end < A.length) {
            int farest = start;
            for (int i = start; i < end; i++) {
                int far = i + A[i];
                if (far > farest)
                    farest = far;
            }
            start = end;
            end = farest+1;
            count++;
        }
        return count;
    }
}