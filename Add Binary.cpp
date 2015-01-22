class Solution {
public:
    string addBinary(string a, string b) {
        string reverse;
        int carry = 0;
        int sum = 0;
        for (int i = 0; i < max(a.length(), b.length()) + 1; i++)
        {
            sum = carry;
            if (i < a.length())
                sum += a[a.length()-1-i] - '0';
            if (i < b.length())
                sum += b[b.length()-1-i] - '0';
            reverse.push_back('0' + (sum%2));
            carry = sum/2;
        }
        
        while (reverse.size()>1)
        {
            if (reverse.back() == '0')
                reverse.pop_back();
            else
                break;
        }
        
        string add;
        for (auto it = reverse.rbegin(); it != reverse.rend(); it++)
        {
            add.push_back(*it);
        }
        return add;
    }
};
