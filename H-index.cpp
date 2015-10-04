class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = (int)citations.size();
        vector<int> count(N + 1);
        for (auto citation : citations) {
            if (citation >= N)
                count[N]++;
            else
                count[citation]++;
        }
        int sum = 0;
        for (int h = N; h >= 0; h--) {
            sum += count[h];
            if (sum >= h)
                return h;
        }
        return 0;
    }
};

