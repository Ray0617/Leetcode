public class Solution {
    public int findFirstGreater(int[] A, int target) {
        int upper = A.length;
        int lower = -1;
        while (upper - lower > 1) {
            int mid = (upper + lower) / 2;
            if (A[mid] > target)
                upper = mid;
            else
                lower = mid;
        }
        return upper;
    }
    public int[] searchRange(int[] A, int target) {
        int[] ret = new int [2];
        ret[0] = -1;
        ret[1] = -1;
        if (A.length == 0)
            return ret;
        
        int start = findFirstGreater(A, target - 1);
        if (start >= A.length)
            return ret;
            
        int end = findFirstGreater(A, target) - 1;
        if (end < start || end >= A.length)
            return ret;

        ret[0] = start;
        ret[1] = end;
        return ret;
    }
}