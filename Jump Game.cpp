class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int end = 1;
        while (end < nums.size()) {
            int farest = end - 1;
            for (int i = start; i < end; i++) {
                if (i + nums[i] > farest)
                    farest = i + nums[i];
            }
            if (farest == end - 1)
                return false;
            start = end;
            end = farest + 1;
        }
        return true;
    }
};
