class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // assert(!nums.empty());
        vector<int> max_product(nums.size());
        vector<int> min_product(nums.size());
        max_product[0] = nums[0];
        min_product[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            max_product[i] = max(nums[i], max(nums[i] * max_product[i-1], nums[i] * min_product[i-1]));
            min_product[i] = min(nums[i], min(nums[i] * max_product[i-1], nums[i] * min_product[i-1]));
            if (max_product[i] > result)
                result = max_product[i];
        }
        return result;
    }
};

