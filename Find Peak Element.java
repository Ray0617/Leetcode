public class Solution {
    public int findPeakElement(int[] num) {
        if (num.length == 0)
            return 0;
            
        int left = -1;
        int right = num.length;
        int mid = (left + right)/2;
        while (mid - left > 1 || right - mid > 1) {
            if (mid - left > 1) {
                int leftmid = (mid + left) / 2;
                if (num[leftmid] <= num[mid]) {
                    left = leftmid;
                }
                else {
                    right = mid;
                    mid = leftmid;
                }
            }
            if (right - mid > 1) {
                int rightmid = (mid + right) / 2;
                if (num[rightmid] <= num[mid]) {
                    right = rightmid;
                }
                else {
                    left = mid;
                    mid = rightmid;
                }
            }
        }
        return mid;
    }
}