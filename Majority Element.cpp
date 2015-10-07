class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[num.size() / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val;
        int count = 0;
        for (auto num : nums) {
            if (count == 0) {
                count++;
                val = num;
            } else if (num == val) {
                count++;
            } else {
                count--;
            }
        }
        return val;
    }
};
