public class Solution {
    private void find(List<Integer> chosen, List<Integer> num, int target, List<List<Integer>> result) {
        if (target == 0) {
            List<Integer> clone = new ArrayList<Integer>(chosen);
	        result.add(clone);
            return;
        }
        if (num.isEmpty())
            return;
        
        List<Integer> candidates = new ArrayList<Integer>();
        int sum = 0;
        for (Integer i : num) {
            if (i > target)
                break;
            candidates.add(i);
            sum += i;
        }
        if (sum < target)
            return;
            
        Integer biggest = candidates.get(candidates.size() - 1);
        candidates.remove(candidates.size() - 1);
        // select one biggest at least
        chosen.add(0, biggest);
        find(chosen, candidates, target - biggest, result);
        
        // selet no biggest at all
        chosen.remove(0);
        while (!candidates.isEmpty() && candidates.get(candidates.size() - 1) == biggest)
            candidates.remove(candidates.size() - 1);
        find(chosen, candidates, target, result);
    }
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        Arrays.sort(num);
        List<Integer> list_num = new ArrayList<Integer>();
        for (int i = 0; i < num.length; i++)
            list_num.add(num[i]);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> chosen = new ArrayList<Integer>();
        find(chosen, list_num, target, result);
        return result;
    }
}