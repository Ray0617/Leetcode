class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 0)
            return 0;
            
        int left = -1;
        int right = num.size();
        int mid = (left + right) / 2;
        while (mid - left > 1 || right - mid > 1) {  // try to converge left-mid-right s.t. num[mid] is biggest, and they are neighbors
            if (mid - left > 1) {
                int leftmid = (mid + left) / 2;
                if (num[leftmid] < num[mid])
                    left = leftmid;
                else {
                    right = mid;
                    mid = leftmid;
                }
            }
            if (right - mid > 1) {
                int rightmid = (right + mid) / 2;
                if (num[rightmid] < num[mid]) 
                    right = rightmid;
                else {
                    left = mid;
                    mid = rightmid;
                }
            }
        }
        return mid;
    }
};