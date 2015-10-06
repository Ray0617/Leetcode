class Solution {
public:
    void permuteUnique(map<int, int>& counts, vector<int>& solution, vector<vector<int>>& result, int len) {
        if (solution.size() == len) {
            result.push_back(solution);
            return;
        }
        for (auto it = counts.begin(); it != counts.end(); it++) {
            int num = it->first;
            int count = it->second;
            if (count > 0) {
                it->second--;
                solution.push_back(num);
                permuteUnique(counts, solution, result, len);
                solution.pop_back();
                it->second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> counts;
        for (auto num : nums)
            counts[num] += 1;
        vector<int> solution;
        permuteUnique(counts, solution, result, nums.size());
        return result;
    }
};

