class Solution {
public:
    
    int romanToInt(string s) {
        map<char, int> ch2int;
        ch2int.insert(make_pair('I', 1));
        ch2int.insert(make_pair('V', 5));
        ch2int.insert(make_pair('X', 10));
        ch2int.insert(make_pair('L', 50));
        ch2int.insert(make_pair('C', 100));
        ch2int.insert(make_pair('D', 500));
        ch2int.insert(make_pair('M', 1000));
        int result = 0;
        int max_num = 0;
        reverse(s.begin(), s.end());
        for (auto ch : s) {
            int val = ch2int[ch];
            if (max_num <= val)
                result += val;
            else
                result -= val;
            if (max_num < val)
                max_num = val;
        }
        return result;
    }
};
