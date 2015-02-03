class Solution {
public:
    bool check(string s, multiset<string>& comp) {
        unsigned len = (*comp.begin()).length();
        multiset<string> strs;
        for (unsigned i = 0; i < s.length(); i += len) {
            string sub = s.substr(i, len);
            if (comp.find(sub) == comp.end())
                return false;
            strs.insert(sub);
        }
        return (strs == comp);
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.empty()) {
            for (unsigned i = 0; i < S.length(); i++)
                ret.push_back(i);
            return ret;
        }
        multiset<string> comp;
        for (unsigned i = 0; i < L.size(); i++) {
            comp.insert(L[i]);
        }

        int len = L.size() * L[0].length();
        for (unsigned i = 0; i < S.length(); i++) {
            if (i + len > S.length())
                break;
            if (check(S.substr(i, len), comp))
                ret.push_back(i);
        }
        return ret;
    }
};