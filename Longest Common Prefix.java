public class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ret = new String();
        if (strs.length == 0) {
            return ret;
        }
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0].charAt(i);
            for (int s = 1; s < strs.length; s++) {
                if (strs[s].length() <= i || strs[s].charAt(i) != ch)
                    return ret;
            }
            ret += ch;
        }
        return ret;
    }
}