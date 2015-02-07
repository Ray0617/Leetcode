class Solution {
public:
    void nextPermutation(vector<int> &num) {
        for (int i = (int)num.size() - 1; i >= 1; i--) {
            if (num[i-1] < num[i]) {
                // find one that just bigger or equal than num[i-1]
                int arg_j = num.size() - 1;
                for (int j = i; j < num.size(); j++) {  // might be optimized by binary seek
                    if (num[j] <= num[i-1]) {
                        arg_j = j - 1;
                        break;
                    }
                }
                int temp = num[i-1];
                num[i-1] = num[arg_j];
                num[arg_j] = temp;
                sort(num.begin() + i, num.end());
                return;
            }
        }
        sort(num.begin(), num.end());
    }
};