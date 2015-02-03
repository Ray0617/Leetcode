public class Solution {
    private boolean check(String S, String[] L) {
        boolean[] test = new boolean[L.length];
        int wlen = L[0].length();
        for (int i = 0; i < S.length(); i += wlen) {
            String sub = S.substring(i, i+wlen);
            boolean found = false;
            for (int j = 0; j < L.length; j++) {
                if (!test[j] && L[j].equals(sub)) {
                    found = true;
                    test[j] = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
    public List<Integer> findSubstring(String S, String[] L) {
        List<Integer> ret = new ArrayList<Integer>();
        if (L.length == 0) {
            for (int i = 0; i < S.length(); i++)
                ret.add(i);
            return ret;
        }
        int wlen = L[0].length();
        int len = wlen * L.length;
        for (int i = 0; i < S.length(); i++) {
            if (i + len > S.length())
                break;
            if (check(S.substring(i, i + len), L))
                ret.add(i);
        }
        return ret;
    }
}