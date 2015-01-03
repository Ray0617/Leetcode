public class Solution {
    public int numTrees(int n) {
        if (caches.isEmpty())
        {
            caches.add(new Integer(1));
            caches.add(new Integer(1));
        }
        if (n < caches.size())
            return caches.get(n);
        for (int i = caches.size(); i <= n; i++)
        {
            int num = 0;
            for (int left = 0; left <= i - 1; left++)
            {
                int right = i - 1 - left;
                num += caches.get(left) * caches.get(right);
            }
            caches.add(new Integer(num));
        }
        return caches.get(n);
    }
    static ArrayList<Integer> caches = new ArrayList<Integer>();
}