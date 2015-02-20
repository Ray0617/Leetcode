public class Solution {
    public int longestConsecutive(int[] num) {
        HashSet<Integer> cache = new HashSet<Integer>();
        for (int i = 0; i < num.length; i++) {
            cache.add(num[i]);
        }
        HashSet<Integer> checked = new HashSet<Integer>();
        int max_len = 0;
        for (int i = 0; i < num.length; i++) {
            if (checked.contains(num[i]))
                continue;
            int len = 1;
            int n = num[i] + 1;
            while (cache.contains(n)) {
                checked.add(n);
                n++;
                len++;
            }
            n = num[i] - 1;
            while (cache.contains(n)) {
                checked.add(n);
                n--;
                len++;
            }
            if (len > max_len)
                max_len = len;
        }
        return max_len;
    }
}