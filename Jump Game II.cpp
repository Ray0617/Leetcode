class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 0)
            return 0;
            
        int count = 0;
        int start = 0;
        int end = 1;
        while (end < n) {
            int farest = start;
            for (int i = start; i < end; i++) {
                if (i + A[i] > farest)
                    farest = i + A[i];
            }
            start = end;
            end = farest + 1;
            count++;
        }
        return count;
    }
    // version 1 Time Limit Exceeded
    int jump1(int A[], int n) {
        if (n <= 0)
            return 0;
        vector<int> minJump(n);
        for (unsigned i = 0; i < minJump.size(); i++)
            minJump[i] = INT_MAX;
        minJump[0] = 0;
        for (unsigned i = 0; i < minJump.size(); i++) {
            for (unsigned j = 1; j <= A[i]; j++) {
                if (i+j >= n)
                    break;
                if (minJump[i]+1 < minJump[i+j])
                    minJump[i+j] = minJump[i]+1;
            }
        }
        return minJump[n-1];
    }
};