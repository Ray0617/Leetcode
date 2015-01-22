class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> cache;
        for (int i = 0; i < numbers.size(); i++) {
            if (cache.find(target - numbers[i]) != cache.end()) {
                vector<int> ret;
                ret.push_back(cache[target-numbers[i]]+1);
                ret.push_back(i+1);
                return ret;
            }
            cache[numbers[i]] = i;
        }
        return vector<int>();
    }
};