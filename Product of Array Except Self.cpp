class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productFront(nums.size());
        productFront[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            productFront[i] = productFront[i-1] * nums[i-1];
        }
        vector<int> productBack(nums.size());
        productBack.back() = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            productBack[i] = productBack[i+1] * nums[i+1];
        }
        
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++)
            result[i] = productFront[i] * productBack[i];
            
        return result;
    }
};

