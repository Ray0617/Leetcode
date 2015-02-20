public class Solution {
    public boolean isMatch(String s, String p) {
        int si = 0;
        int pi = 0;
        int sm = -1;
        int pm = -1;
        while (si < s.length()) {
            if (pi < p.length() && (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '?')) {
                si++;
                pi++;
                continue;
            }
            if (pi < p.length() && p.charAt(pi) == '*') {
                pi++;
                pm = pi;
                sm = si;
                continue;
            }
            if (pm >= 0) {
                sm++;
                pi = pm;
                si = sm;
                continue;
            }
            return false;
        }
       	while (pi < p.length()) {
       		if (p.charAt(pi) != '*')
       			return false;
        	pi++;
       	}
       	return true;
    }
}