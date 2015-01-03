class Solution {
public:
    int numTrees(int n) {
        static std::vector<int> m_num;
        if (m_num.empty())
        {
            m_num.push_back(1);
            m_num.push_back(1);
        }
        if (n < m_num.size())
            return m_num[n];
        for (int i = m_num.size(); i <= n; i++)
        {
            int num = 0;
            for (int left = 0; left <= i-1; left++)
            {
                int right = i - 1 - left;
                num += m_num[left] * m_num[right];
            }
            m_num.push_back(num);
        }
        return m_num[n];
    }
};