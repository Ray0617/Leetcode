class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10)
            return vector<string>();
        map<char, int> ch2int;
        ch2int.insert(make_pair('A', 0));
        ch2int.insert(make_pair('C', 1));
        ch2int.insert(make_pair('G', 2));
        ch2int.insert(make_pair('T', 3));
        char int2ch[4] = {'A', 'C', 'G', 'T'};
        int result = 0;
        for (int i = 0; i < 10; i++) {
            result *= 4;
            result += ch2int[s[i]];
        }
        set<int> patterns;
        set<int> dup_patterns;
        patterns.insert(result);
        for (int i = 10; i < (int)s.length(); i++) {
            result *= 4;
            result &= 0xfffff;
            result += ch2int[s[i]];
            if (patterns.find(result) != patterns.end())
                dup_patterns.insert(result);
            patterns.insert(result);
        }
        vector<string> ret;
        for (auto pattern : dup_patterns) {
            string str;
            for (int i = 0; i < 10; i++) {
                str = int2ch[pattern % 4] + str;
                pattern /= 4;
            }
            ret.push_back(str);
        }
        return ret;
    }
};

