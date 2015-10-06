class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int w = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            if (nums[r] != val)
                nums[w++] = nums[r];
        }
        return w;
    }
};

