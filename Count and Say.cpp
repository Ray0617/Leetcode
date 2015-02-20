
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int c = 1; c < n; c++) {
			string temp = result;
			result = "";
            char digit = temp[0];
            int count = 0;
            for (int i = 0; i < temp.length(); i++) {
                if (digit == temp[i]) {
                    count++;
                }
                else {
                    result += to_string(count);
                    result += digit;
                    digit = temp[i];
                    count = 1;
                }
            }
            result += to_string(count);
            result += digit;
        }
        return result;
    }
};