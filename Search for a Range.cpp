
class Solution {
public:
    int findFirstGreater(int A[], int n, int target) {
        if (n == 0)
            return -1;
		if (n == 1)
			return (A[0] > target)?0:1;
        if (A[n-1] <= target)
            return n;
        if (A[0] > target)
            return 0;
        int start = 0;  // smaller or equal to target
        int end = n - 1;    // greater than target
        while (end - start > 1) {
            int mid = (start + end) / 2;
            if (A[mid] <= target)
                start = mid;
            else 
                end = mid;
        }
        return end;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2);
        ret[0] = findFirstGreater(A, n, target - 1);
        ret[1] = findFirstGreater(A, n, target) - 1;
        if (ret[1] < ret[0])
            ret[0] = ret[1] = -1;
		else if (ret[0] == ret[1]) {
			if (ret[0] < 0 || A[ret[0]] != target)
				ret[0] = ret[1] = -1;
		}
        return ret;
    }
};