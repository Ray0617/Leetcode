public class Solution {
    public void comb(String head, String digits, List<String> ret)
    {
        if (digits.isEmpty()) {
            ret.add(head);            
            return;
        }
        char first = digits.charAt(0);
        digits = digits.substring(1);
        switch (first) {
            case '2':
                comb(head + 'a', digits, ret);
                comb(head + 'b', digits, ret);
                comb(head + 'c', digits, ret);
                break;
            case '3':
                comb(head + 'd', digits, ret);
                comb(head + 'e', digits, ret);
                comb(head + 'f', digits, ret);
                break;
            case '4':
                comb(head + 'g', digits, ret);
                comb(head + 'h', digits, ret);
                comb(head + 'i', digits, ret);
                break;
            case '5':
                comb(head + 'j', digits, ret);
                comb(head + 'k', digits, ret);
                comb(head + 'l', digits, ret);
                break;
            case '6':
                comb(head + 'm', digits, ret);
                comb(head + 'n', digits, ret);
                comb(head + 'o', digits, ret);
                break;
            case '7':
                comb(head + 'p', digits, ret);
                comb(head + 'q', digits, ret);
                comb(head + 'r', digits, ret);
                comb(head + 's', digits, ret);
                break;
            case '8':
                comb(head + 't', digits, ret);
                comb(head + 'u', digits, ret);
                comb(head + 'v', digits, ret);
                break;
            case '9':
                comb(head + 'w', digits, ret);
                comb(head + 'x', digits, ret);
                comb(head + 'y', digits, ret);
                comb(head + 'z', digits, ret);
                break;
            
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> ret = new ArrayList<String>();
        comb("", digits, ret);
        return ret;
    }
}