class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size() - 1;
        for (; i >= 1; i--) {
            if (nums[i-1] < nums[i])
                break;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // nums[i-1] < nums[i] 
        int val = nums[i-1];
        int lower = i;
        int upper = (int)nums.size() - 1;
        if (nums[upper] > val)
            lower = upper;
        else {
            while (lower < upper - 1) {
                // assert(nums[lower] > val && nums[upper] <= val);
                int mid = (lower + upper) / 2;
                if (nums[mid] > val)
                    lower = mid;
                else
                    upper = mid;
            }
        }
        nums[i-1] = nums[lower];
        nums[lower] = val;
        sort(nums.begin() + i, nums.end());
    }
};

