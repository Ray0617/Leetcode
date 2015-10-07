class Solution {
public:
    void combinationSum2(vector<int>& candidates, int start, int target, vector<int>& solution, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(solution);
            return;
        }
        if (start >= candidates.size())
            return;
        if (candidates[start] > target)
            return;
        int count = 0;
        while (start + count < candidates.size() && candidates[start] == candidates[start + count])
            count++;
        for (int i = 0; i <= count; i++) {
            combinationSum2(candidates, start + count, target - i * candidates[start], solution, result);
            if (i != count)
                solution.push_back(candidates[start]);
        }
        solution.resize(solution.size() - count);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target, solution, result);
        return result;
    }
};

