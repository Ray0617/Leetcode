class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // (x, y) -> (y, W-x) -> (W-x, H-y) -> (H-y, x) -> (x, y)
        unsigned N = matrix.size();
        for (unsigned i = 0; i < (N + 1) / 2; i++) {
            for (unsigned j = 0; j < N / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N-1-j][i];
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                matrix[j][N-1-i] = temp;
            }
        }
    }
};