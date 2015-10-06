class Solution {
public:
    int search(int A[], int target, int start, int end) {
        if (target == A[start])
            return start;
        if (target == A[end])
            return end;
        if (end <= start)
            return -1;
        int mid = (start + end) / 2;
        if( A[start] < target && target < A[mid] || A[start] > A[mid] && (target > A[start] || target < A[mid]) )
            return search(A, target, start + 1, mid);
        else
            return search(A, target, mid, end - 1);
    }
    int search(int A[], int n, int target) {
        if (n == 0)
            return -1;
        return search(A, target, 0, n-1);
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        bool rotation = nums[0] > nums.back();
        if (rotation && target > nums.back() && target < nums[0])
            return -1;
        if (!rotation && (target < nums[0] || target > nums.back()))
            return -1;
            
        int lower = 0;
        int upper = nums.size() - 1;
        if (target == nums[upper])
            return upper;
        
        while (lower < upper - 1) {
            // assert(lower <= target && target < upper)
            int mid = (lower + upper) / 2;
            if (rotation) {
                if (nums[mid] > nums[lower]) {
                    if (target >= nums[lower] && target < nums[mid]) {
                        upper = mid;
                        rotation = false;
                    } else
                        lower = mid;
                }
                else {
                    if (target >= nums[mid] && target < nums[upper]) {
                        lower = mid;
                        rotation = false;
                    }
                    else
                        upper = mid;
                }
            } else {
                if (nums[mid] <= target)
                    lower = mid;
                else
                    upper = mid;
            }
        }
        if (target == nums[lower])
            return lower;
        return -1;
    }
};
