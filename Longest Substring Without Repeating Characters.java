public class Solution {
    public int lengthOfLongestSubstring(String s) {
        boolean[] test = new boolean [256];
        int longest = 0;
        int start = 0;  // include
        int end = 0;    // exclude
        while (end < s.length()) {
            if (!test[s.charAt(end)]) {
                test[s.charAt(end)] = true;
            }
            else {
                while (s.charAt(start) != s.charAt(end)) {
                    test[s.charAt(start)] = false;
                    start++;
                }
                start++;
            }
            end++;
            if (end - start > longest)
                longest = end - start;
        }
        return longest;
    }
}