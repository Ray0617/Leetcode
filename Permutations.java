public class Solution {
    private void divideAndConquer(List<Integer> selects, List<Integer> num, List<List<Integer>> result) {
        if (num.isEmpty()) {
            result.add(new ArrayList<Integer>(selects));
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            int n = num.get(i);
            num.remove(i);
            selects.add(n);
            divideAndConquer(selects, num, result);
            selects.remove(selects.size() - 1);
            num.add(i, n);
        }
    }
    public List<List<Integer>> permute(int[] num) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> selects = new ArrayList<Integer>();
        List<Integer> numbers = new ArrayList<Integer>();
        for (int i = 0; i < num.length; i++)
            numbers.add(num[i]);
        divideAndConquer(selects, numbers, result);
        return result;
    }
}