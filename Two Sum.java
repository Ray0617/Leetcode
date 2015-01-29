public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> cache = new HashMap<Integer, Integer>();
        for (int i = 0; i < numbers.length; i++) {
            if (cache.containsKey(target - numbers[i])) {
                int [] ret = new int [2];
                ret[0] = cache.get(target - numbers[i]) + 1;
                ret[1] = i + 1;
                return ret;
            }
            cache.put(numbers[i], i);
        }
        return null;
    }
}