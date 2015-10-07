class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		vector<int> max_rob(nums.size()); // max_rob[i]: max profit to rob [0..i]
		max_rob[0] = nums[0];
		max_rob[1] = max(nums[0], nums[1]);
		for (int i = 2; i < (int)nums.size(); i++) {
			max_rob[i] = max(max_rob[i-2] + nums[i], max_rob[i-1]);
		}
		return max_rob.back();
	}
};


