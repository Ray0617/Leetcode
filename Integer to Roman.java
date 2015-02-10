public class Solution {
    private String digitToRoman(int digit, char one, char five, char ten) {
        StringBuilder str = new StringBuilder("");
        if (digit == 4 || digit == 9)
            str.append(one);
        if (digit >= 4 && digit <= 8)
            str.append(five);
        if (digit == 9)
            str.append(ten);
        if (digit % 5 <= 3) {
            for (int i = 0; i < digit % 5; i++) {
                str.append(one);
            }
        }
        return str.toString();
    }
    public String intToRoman(int num) {
        int d1 = num % 10;
        String s1 = digitToRoman(d1, 'I', 'V', 'X');
        num /= 10;
        int d2 = num % 10;
        String s2 = digitToRoman(d2, 'X', 'L', 'C');
        num /= 10;
        int d3 = num % 10;
        String s3 = digitToRoman(d3, 'C', 'D', 'M');
        num /= 10;
        int d4 = num % 10;
        String s4 = digitToRoman(d4, 'M', '?', '?');
        return s4 + s3 + s2 + s1;
    }
}