class Solution {
public:
    string roman(int digit, string n1, string n5, string n10)
    {
        switch (digit)
        {
            case 0:
                return "";
            case 1:
                return n1;
            case 2:
                return n1 + n1;
            case 3:
                return n1 + n1 + n1;
            case 4:
                return n1 + n5;
            case 5:
                return n5;
            case 6:
                return n5 + n1;
            case 7:
                return n5 + n1 + n1;
            case 8:
                return n5 + n1 + n1 + n1;
            case 9:
                return n1 + n10;
            default:
                return "";
        }
    }
    string intToRoman(int num) {
        string ret;
        // I: 1; V: 5; X: 10; L: 50; C: 100; D: 500; M: 1000
        ret = roman(num % 10, "I", "V", "X") + ret;
        num /= 10;
        ret = roman(num % 10, "X", "L", "C") + ret; 
        num /= 10;
        ret = roman(num % 10, "C", "D", "M") + ret;
        num /= 10;
        ret = roman(num % 10, "M", "?", "?") + ret;
        return ret;
    }
};