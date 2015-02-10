public class Solution {
    public int removeDuplicates(int[] A) {
        int w = 0;
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for (int r = 0; r < A.length; r++) {
            if (!count.containsKey(A[r]))
                count.put(A[r], 0);
            if (count.get(A[r]) == 2)
                continue;
            count.put(A[r], count.get(A[r])+1);
            A[w++] = A[r];
        }
        return w;
    }
}