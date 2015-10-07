class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> windows;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (windows.find(nums[i]) != windows.end())
                return true;
            windows.insert(nums[i]);
            if (windows.size() > k)
                windows.erase(nums[i-k]);
        }
        return false;
    }
};

