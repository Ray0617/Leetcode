class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int w = 1;
        int val = nums[0];
        int count = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == val) {
                count++;
                if (count <= 2) {
                    nums[w++] = val;
                }
            } else {
                val = nums[i];
                count = 1;
                nums[w++] = val;
            }
        }
        return w;
    }
};

