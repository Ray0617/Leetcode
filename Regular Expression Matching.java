public class Solution {
    public boolean isMatch(String s, String p) {
        if (s.isEmpty() && p.isEmpty())
            return true;
        if (p.isEmpty())
            return false;
        if (s.isEmpty())
            return (p.length() >= 2 && p.charAt(1) == '*' && isMatch(s, p.substring(2)) );
        
        if (p.length() >= 2 && p.charAt(1) == '*') 
            return isMatch(s, p.substring(2)) || (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') && isMatch(s.substring(1), p);
        if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')
            return isMatch(s.substring(1), p.substring(1));
        return false;
    }
}