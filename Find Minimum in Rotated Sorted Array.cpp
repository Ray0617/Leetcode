class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int lower = 0;
        int upper = nums.size() - 1;
        if (nums[lower] < nums[upper])
            return nums[lower];
        while (lower < upper - 1) {
            int mid = (lower + upper) / 2;
            if (nums[lower] < nums[mid])
                lower = mid;
            else
                upper = mid;
        }
        return nums[upper];
    }
};

