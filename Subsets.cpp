class Solution {
public:
	void subsets(vector<int>& nums, int start, vector<int>& solution, vector<vector<int>>& result) {
		if (start == nums.size()) {
			result.push_back(solution);
			return;
		}
		subsets(nums, start + 1, solution, result);
		solution.push_back(nums[start]);
		subsets(nums, start + 1, solution, result);
		solution.pop_back();
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> solution;
		sort(nums.begin(), nums.end());
		subsets(nums, 0, solution, result);
		return result;
	}
};


