class MinStack {
private:
    stack<int> m_value;
    stack<int> m_min;
public:
    void push(int x) {
        m_value.push(x);
        if (m_min.empty() || x <= m_min.top()) 
            m_min.push(x);
    }

    void pop() {
        int val = m_value.top();
        m_value.pop();
        if (m_min.top() == val)
            m_min.pop();
    }

    int top() {
        return m_value.top();
    }

    int getMin() {
        return m_min.top();
    }
};