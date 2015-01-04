class Solution {
public:
    void divideAndConquer(vector<int> &head, vector<int> &num, vector<vector<int> >& perms)
    {
        if (num.empty())
        {
            perms.push_back(head);
            return;
        }
        set<int> used;
        for (int i = 0; i < num.size(); i++)
        {
            if (used.find(num[i]) != used.end())
                continue;
            head.push_back(num[i]);
            int tmp = num[i];
            num[i] = num.back();
            num.pop_back();
            divideAndConquer(head, num, perms);
            num.push_back(num[i]);
            num[i] = tmp;
            head.pop_back();
            used.insert(num[i]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > perms;
        vector<int> head;
        divideAndConquer(head, num, perms);
        return perms;
    }
};