class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
            matrix[i].resize(n);
        int i = 0;
        int j = 0;
        int dir = 0;
        int right = n - 1;
        int bottom = n - 1;
        int left = 0;
        int top = 0;
        for (int num = 1; num <= n * n; num++) {
            matrix[i][j] = num;
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
        return matrix;
    }
};

