public class Solution {
    public String countAndSay(int n) {
        String temp = "1";
        for (int loop = 1; loop < n; loop++) {
            StringBuilder result = new StringBuilder();
            Character digit = temp.charAt(0);
            int count = 0;
            for (int i = 0; i < temp.length(); i++) {
                if (digit == temp.charAt(i)) {
                    count++;
                }
                else {
                    result.append(count);
                    result.append(digit);
                    digit = temp.charAt(i);
                    count = 1;
                }
            }
            result.append(count);
            result.append(digit);
            temp = result.toString();
        }
        return temp;
    }
}