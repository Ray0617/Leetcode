class MinStack {
    private Stack<Integer> m_value = new Stack<Integer>();
    private Stack<Integer> m_min = new Stack<Integer>();
    public void push(int x) {
        m_value.push(x);
        if (m_min.empty() || x <= m_min.peek())
            m_min.push(x);
    }

    public void pop() {
        int val = m_value.pop();
        if (m_min.peek() == val)
            m_min.pop();
    }

    public int top() {
        return m_value.peek();
    }

    public int getMin() {
        return m_min.peek();
    }
}
