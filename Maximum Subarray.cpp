class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		// max_sub_array[i] := max sum end at i
		vector<int> max_sub_array(nums.size());
		max_sub_array[0] = nums[0];
		int result = max_sub_array[0];
		for (int i = 1; i < nums.size(); i++) {
			max_sub_array[i] = nums[i] + max(0, max_sub_array[i-1]);
			if (max_sub_array[i] > result)
				result = max_sub_array[i];
		}
		return result;
	}
};

