public class Solution {
    public boolean isValid(String s) {
        List<Character> parentheses = new ArrayList<Character>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '[' || ch == '{') {
                parentheses.add(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (parentheses.isEmpty())
                    return false;
                char prev = parentheses.get(parentheses.size() - 1);
                parentheses.remove(parentheses.size() - 1);
                if (prev == '(' && ch == ')' || prev == '[' && ch == ']' || prev == '{' && ch == '}')
                    continue;
                return false;
            }
        }
        return parentheses.isEmpty();
    }
}