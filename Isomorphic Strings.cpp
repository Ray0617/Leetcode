class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        map<char, char> s2t;
        map<char, char> t2s;
        for (int i = 0; i < (int)s.length(); i++) {
            char ch_s = s[i];
            char ch_t = t[i];
            if (s2t.find(ch_s) != s2t.end() && s2t[ch_s] != ch_t)
                return false;
            if (t2s.find(ch_t) != t2s.end() && t2s[ch_t] != ch_s)
                return false;
            s2t.insert(make_pair(ch_s, ch_t));
            t2s.insert(make_pair(ch_t, ch_s));
        }
        return true;
    }
};

