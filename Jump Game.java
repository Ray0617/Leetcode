public class Solution {
    public boolean canJump(int[] A) {
        int farest = 0;
        for (int i = 0; i < A.length; i++) {
            if (farest < i)
                return false;
            farest = Math.max(farest, i + A[i]);
            if (farest >= A.length - 1)
                break;
        }
        return true;
    }
}