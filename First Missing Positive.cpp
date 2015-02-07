class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while (A[i] >= 1 && A[i] <= n) {
				int pos = A[i] - 1;
				if (A[i] == A[pos])
					break;
				A[i] = A[pos];
				A[pos] = pos + 1;
			}
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
