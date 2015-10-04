class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            if (nums[r] != 0)
                nums[w++] = nums[r];
        }
        while (w < (int)nums.size())
            nums[w++] = 0;
    }
};
