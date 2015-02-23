bool significantDigitFirstStr(string str1, string str2) {
    for (int i = 0; i < min(str1.length(), str2.length()); i++) {
        if (str1[i] > str2[i])
            return true;
        if (str1[i] < str2[i])
            return false;
    }
    if (str1.length() == str2.length())
        return false;
    if (str1.length() < str2.length())
        return significantDigitFirstStr(str1, str2.substr(str1.length()));
    return significantDigitFirstStr(str1.substr(str2.length()), str2);
}
bool significantDigitFirst(int n1, int n2) {
    string str1 = to_string(n1);
    string str2 = to_string(n2);
    return significantDigitFirstStr(str1, str2);
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), significantDigitFirst);
        if (num.empty() || num[0] == 0)
            return "0";
        string result;
        for (int i = 0; i < num.size(); i++) {
            result += to_string(num[i]);
        }
        return result;
    }
};