class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++) {
            result.push_back(1);
            for (int j = (int)result.size() - 2; j >= 1; j--) {
                result[j] += result[j-1];
            }
        }
        return result;
    }
};

