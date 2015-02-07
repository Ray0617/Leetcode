public class Solution {
    private boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
    private void partition(String s, List<String> substrs, List<List<String>> result) {
        for (int len = 1; len <= s.length(); len++) {
            String substr = s.substring(0, len);
            if (!isPalindrome(substr))
                continue;
            substrs.add(substr);
            if (len == s.length()) {
                List<String> sol = new ArrayList<String>(substrs);
                result.add(sol);
            }
            partition(s.substring(len), substrs, result);
            substrs.remove(substrs.size() - 1);
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<List<String>>();
        List<String> substrs = new ArrayList<String>();
        partition(s, substrs, result);
        return result;
    }
}