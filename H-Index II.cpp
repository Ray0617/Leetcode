class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = (int)citations.size();
        for (int i = 0; i < N; i++) {
            if (citations[i] >= N - i)
                return N - i;
        }
        return 0;
    }
};

