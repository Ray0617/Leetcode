class Solution {
public:
    string fractionToDecimal(int _numerator, int _denominator) {
        if (_numerator == 0)
            return "0";
        string ret;
        bool plus = (_numerator >= 0 && _denominator >= 0) || (_numerator <= 0 && _denominator <= 0);
        unsigned long long numerator = abs((long long)_numerator);
        unsigned long long denominator = abs((long long)_denominator);
        if (!plus)
            ret = "-";
        unsigned long long quotient = numerator / denominator;
        unsigned long long reminder = numerator % denominator;
        ret += to_string(quotient);
        if (reminder == 0)
            return ret;
        ret.push_back('.');
        
        map<unsigned long long, int> backup;
        vector<int> digit;
        int found_index = -1;
        while (reminder > 0) {
            numerator = reminder;
            if (backup.find(numerator) != backup.end()) {
                found_index = backup[numerator];
				break;
            }
            backup[numerator] = digit.size();
            numerator *= 10;
            quotient = numerator / denominator;
            digit.push_back(quotient);
            reminder = numerator % denominator;
        }
        for (unsigned i = 0; i < digit.size(); i++) {
            if (i == found_index)
                ret.push_back('(');
            ret.push_back('0' + digit[i]);
        }
        if (found_index != -1)
            ret.push_back(')');
        return ret;
    }
};