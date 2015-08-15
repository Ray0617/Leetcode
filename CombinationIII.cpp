#include "leetcode.h"

class Solution {
public:
    void combinationSum3(int k, int n, int start, vector<int>& selected, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(selected);
            return;
        }
        if (start > n)
            return;
        combinationSum3(k, n, start + 1, selected, result); // not select start
        selected.push_back(start);
        combinationSum3(k - 1, n, start + 1, selected, result); // select start
        selected.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> selected;
        combinationSum3(k, n, 1, selected, result);
        return result;
    }
};

int main() {
	Solution sol;
	auto result = sol.combinationSum3(2, 6);
	return 0;
}
