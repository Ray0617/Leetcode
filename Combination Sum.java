public class Solution {
    public void divideAndConquer(List<Integer> selects, List<Integer> candidates, int target, List<List<Integer>> ret) {
        if (target == 0) {
            ret.add(new ArrayList<Integer>(selects));
            return;
        }
        if (candidates.isEmpty()) {
            return;
        }
        
        int biggest = candidates.get(candidates.size() - 1);
        candidates.remove(candidates.size() - 1);
        for (int numOfBiggest = 0; numOfBiggest <= target / biggest; numOfBiggest++) {
            for (int i = 0; i < numOfBiggest; i++)
                selects.add(0, biggest);
            target -= numOfBiggest * biggest;
            divideAndConquer(selects, candidates, target, ret);
            target += numOfBiggest * biggest;
            for (int i = 0; i < numOfBiggest; i++)
                selects.remove(0);
        }
        candidates.add(biggest);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        List<Integer> selects = new ArrayList<Integer>();
        Arrays.sort(candidates);
        List<Integer> listCandidates = new ArrayList<Integer>();
        for (int i = 0; i < candidates.length; i++)
            listCandidates.add(candidates[i]);
        divideAndConquer(selects, listCandidates, target, ret);
        return ret;
    }
}