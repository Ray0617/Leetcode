class Solution {
public:
    void divideAndConquer(vector<int>& selects, vector<int>& num, vector<vector<int> >& result) {
        if (num.empty()) {
            result.push_back(selects);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            selects.push_back(num[i]);
            int temp = num[i];
            num[i] = num.back();
            num.pop_back();
            divideAndConquer(selects, num, result);
            num.push_back(num[i]);
            num[i] = temp;
            selects.pop_back();
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> selects;
        divideAndConquer(selects, num, result);
        return result;
    }
};