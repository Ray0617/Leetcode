class Solution {
public:
    bool isPalindrome(string str) {
        int i = 0;
        int j = str.length() - 1;
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void partition(string str, vector<string>& strs, vector<vector<string>>& ret) {
        for (unsigned int i = 1; i <= str.length(); i++) {
            string str1 =  str.substr(0, i);
            if (!isPalindrome(str1)) {
                continue;
            }
            string str2 =  str.substr(i);
            strs.push_back(str1);
            if (i == str.length()) {
                ret.push_back(strs);
            }
            partition(str2, strs, ret);
            strs.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> strs;
        partition(s, strs, ret);
        return ret;
    }
};