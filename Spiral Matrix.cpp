class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        int dir = 0;
        if (n == 1)
            dir = 1;
        while (result.size() < m * n) {
            result.push_back(matrix[i][j]);
            switch (dir) {
                case 0:
                    j++;
                    if (j == right) {
                        dir = 1;
                        top++;
                    }
                    break;
                case 1:
                    i++;
                    if (i == bottom) {
                        dir = 2;
                        right--;
                    }
                    break;
                case 2:
                    j--;
                    if (j == left) {
                        dir = 3;
                        bottom--;
                    }
                    break;
                case 3:
                    i--;
                    if (i == top) {
                        dir = 0;
                        left++;
                    }
                    break;
            }
        }
        return result;
    }
};

