class Solution {
public:
    void combinationSum2(const vector<int>& tail, const vector<int>& num, int target, vector<vector<int> >& result) {
        if (target == 0) {
            vector<int> reverse;
            for (int i = (int)tail.size() - 1; i >= 0; i--) {
                reverse.push_back(tail[i]);
            }
            result.push_back(reverse);
            return;
        }
        vector<int> candidates;
        int sum = 0;
        for (int i = 0; i< num.size(); i++) {
            if (num[i] > target)
                break;
            sum += num[i];
            candidates.push_back(num[i]);
        }
        if (sum < target)
            return;
        
        int last = candidates.back();
        candidates.pop_back();
        vector<int> chosen = tail;
        //select at least one last
        chosen.push_back(last);
        combinationSum2(chosen, candidates, target - last, result);
        // not select last at all
        chosen.pop_back();
        while (!candidates.empty() && candidates.back() == last) {
            candidates.pop_back();
        }
        combinationSum2(chosen, candidates, target, result);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> chosen;
        combinationSum2(chosen, num, target, ret);
        return ret;
    }
};