public class Solution {
    public int[] plusOne(int[] digits) {
        if (digits.length == 0)
            return digits;
        int i = digits.length - 1;
        while (true) {
            digits[i]++;
            if (digits[i] < 10)
                return digits;
            digits[i] = 0;
            i--;
            if (i < 0) {
                int[] ret = new int[digits.length + 1];
                ret[0] = 1;
                System.arraycopy(digits, 0, ret, 1, digits.length);
                return ret;
            }
        }
    }
}