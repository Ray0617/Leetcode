class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> cache(num.begin(), num.end());
        unordered_set<int> checked;
        int max_len = 0;
        for (int i = 0; i < num.size(); i++) {
            if (checked.find(num[i]) != checked.end())
                continue;
            
            int len = 1;
            int n = num[i] + 1;
            while (cache.find(n) != cache.end()) {
                checked.insert(n);
                n++;
                len++;
            }
            n = num[i] - 1;
            while (cache.find(n) != cache.end()) {
                checked.insert(n);
                n--;
                len++;
            }
            if (len > max_len)
                max_len = len;
        }
        return max_len;
    }
};