class Solution {
public:
    void combinationSum(vector<int>& selected, vector<int> &candidates, int target, vector<vector<int> >& ret) {
        if (target == 0) {
            ret.push_back(selected);
            return;
        }
        if (candidates.empty()) {
            return;
        }
        int biggest = candidates.back();
        candidates.pop_back();
		vector<int> temp = selected;
        for (int i = 0; i <= target / biggest; i++) {
			temp.clear();
            for (int c = 0; c < i; c++) {
                temp.push_back(biggest);
            }
			for (int s = 0; s < selected.size(); s++)
				temp.push_back(selected[s]);
            target -= biggest * i;
            combinationSum(temp, candidates, target, ret);
            target += biggest * i;
		}
		candidates.push_back(biggest);
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> sel;
        sort(candidates.begin(), candidates.end());
        combinationSum(sel, candidates, target, ret);
        return ret;
    }
};