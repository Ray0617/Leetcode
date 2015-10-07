class Solution {
public:
    void combinationSum3(int k, int sum, int n, vector<int>& solution, vector<vector<int>>& result) {
        if (sum < 0)
            return;
        if (k == 0) {
            if (sum == 0)
                result.push_back(solution);
            return;
        }
        if (n > sum)
            return;
        for (int i = n; i <= 9; i++) {
            solution.push_back(i);
            combinationSum3(k-1, sum - i, i + 1, solution, result);
            solution.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        combinationSum3(k, n, 1, solution, result);
        return result;
    }
};

