public class Solution {
    public int atoi(String str) {
        int status = 0;
        int sign = +1;
        long ret = 0;
        for (int i = 0; i < str.length(); i++) {
            switch (status) {
                case 0:
                    if (Character.isWhitespace(str.charAt(i)))
                        break;
                    else if (str.charAt(i) == '-') {
                        sign = -1;
                        status = 1;
                        break;
                    }
                    else if (str.charAt(i) == '+') {
                        sign = +1;
                        status = 1;
                        break;
                    }
                    status = 1;
                    // not break intentionally
                case 1:
                    if (Character.isDigit(str.charAt(i))) {
                        ret *= 10;
                        ret += str.charAt(i) - '0';
                        if (sign * ret > Integer.MAX_VALUE)
                            return Integer.MAX_VALUE;
                        if (sign * ret < Integer.MIN_VALUE)
                            return Integer.MIN_VALUE;
                    }
                    else
                        return (int)(sign * ret);
                    break;
            }
        }
        return (int)(sign * ret);
    }
}