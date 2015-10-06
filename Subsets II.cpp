class Solution {
public:
    void subsetsWithDup(deque<int>& nums, vector<int>& solution, vector<vector<int>>& result) {
        if (nums.empty()) {
            result.push_back(solution);
            return;
        }
        int val = nums.front();
        int count = 0;
        while (!nums.empty() && nums.front() == val) {
            count++;
            nums.pop_front();
        }
        
        subsetsWithDup(nums, solution, result);
        for (int i = 0; i < count; i++) {
            solution.push_back(val);
            subsetsWithDup(nums, solution, result);
        }
        
        for (int i = 0; i < count; i++) {
            solution.pop_back();
            nums.push_front(val);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(nums.begin(), nums.end());
        deque<int> deq(nums.begin(), nums.end());
        subsetsWithDup(deq, solution, result);
        return result;
    }
};

