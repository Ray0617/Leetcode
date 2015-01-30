public class Solution {
    Map<Integer, Map<Integer, List<List<Integer>>>> cache = new HashMap<Integer, Map<Integer, List<List<Integer>>>>();
    public List<List<Integer>> combine(int n, int k) {
        // C(n, k) = C(n-1, k-1) + C(n-1, k)
        if (!cache.containsKey(n)) {
            cache.put(n, new HashMap<Integer, List<List<Integer>>>());
        }
        if (!cache.containsKey(n-1)) {
            cache.put(n-1, new HashMap<Integer, List<List<Integer>>>());
        }
        if (!cache.get(n).containsKey(k)) {
            List<List<Integer>> c = new ArrayList<List<Integer>>();
            if (k == 0 || n == 0) {
                List<Integer> e = new ArrayList<Integer>();
                c.add(e);
            }
            else if (n == k) {
                List<Integer> e = new ArrayList<Integer>();
                for (int i = 1; i <= n; i++)
                    e.add(i);
                c.add(e);
            }
            else {
                List<List<Integer>> c1 = combine(n-1, k-1);
                List<List<Integer>> c2 = combine(n-1, k);
                for (List<Integer> v : c1) {
                    List<Integer> vv = new ArrayList<Integer>(v);
                    vv.add(n);
                    c.add(vv);
                }
                for (List<Integer> v : c2) {
                    c.add(v);
                }
            }
            cache.get(n).put(k, c);
        }
        return cache.get(n).get(k);
    }
}