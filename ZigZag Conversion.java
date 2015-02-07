public class Solution {
    public String convert(String s, int nRows) {
        if (nRows == 1)
            return s;
        String[] arr = new String[nRows];
        for (int i = 0; i < nRows; i++) {
            arr[i] = new String();
        }
        int r = 0;
        boolean down = true;
        for (char ch : s.toCharArray()) {
            arr[r] += ch;
            if (down) {
                r++;
                if (r >= nRows - 1)
                    down = false;
            }
            else {
                r--;
                if (r <= 0) 
                    down = true;
            }
        }
        String ret = "";
        for (String str : arr) {
            ret += str;
        }
        return ret;
    }
}