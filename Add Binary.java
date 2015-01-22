public class Solution {
    public String addBinary(String a, String b) {
        String ret = "";
        int carry = 0;
        int index = 0;
        while (carry > 0 || index < a.length() || index < b.length()) {
            int digit = carry;
            if (index < a.length() && a.charAt(a.length()-1-index) == '1')
                digit++;
            if (index < b.length() && b.charAt(b.length()-1-index) == '1')
                digit++;
            carry = digit / 2;
            digit = digit % 2;
            ret = (digit==1?"1":"0") + ret;
            index++;
        }
        if (ret.isEmpty())
            return "0";
        return ret;
    }
}
