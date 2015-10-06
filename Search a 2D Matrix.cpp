class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        if (target < matrix[0][0])
            return false;
        if (target > matrix.back().back())
            return false;
        if (target == matrix.back().back())
            return true;
        int lower = 0;
        int upper = matrix.size() * matrix[0].size() - 1;
        while (lower < upper - 1) {
            int mid = (lower + upper) / 2;
            int val = matrix[mid / matrix[0].size()][mid % matrix[0].size()];
            if (val <= target)
                lower = mid;
            else
                upper = mid;
        }
        
        return (target == matrix[lower / matrix[0].size()][lower % matrix[0].size()]);

    }
};

