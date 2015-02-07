public class Solution {
    public void nextPermutation(int[] num) {
        for (int i = num.length - 1; i >= 1; i--) {
            if (num[i-1] < num[i]) {
                // try to find the max one in num[i:] which is greater than num[i-1]
                for (int j = num.length - 1; j >= i; j--) {
                    if (num[j] > num[i-1]) {
                        // swap num[i-1] and num[j]
                        int temp = num[i-1];
                        num[i-1] = num[j];
                        num[j] = temp;
                        Arrays.sort(num, i, num.length);
                        return;
                    }
                }
            }
        }
        Arrays.sort(num);
    }
}