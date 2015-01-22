class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return digits;
            
        int index = digits.size() - 1;
        while (index >= 0)
        {
            digits[index]++;
            if (digits[index] >= 10)
            {
                digits[index] = 0;
                index--;
            }
            else
                break;
        }
        if (index < 0)
        {
            vector<int> ret;
            ret.push_back(1);
            for (int i = 0; i < digits.size(); i++)
                ret.push_back(digits[i]);
            return ret;
        }
        return digits;
    }
};