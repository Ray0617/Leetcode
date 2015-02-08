class LRUCache{
public:
    LRUCache(int capacity)
        : m_capacity(capacity)
    {}
    
    int get(int key) {
        if (m_caches.find(key) == m_caches.end()) {
            return -1;
        }
		update(key);
        return m_caches[key].first;
    }
    
    void set(int key, int value) {
        if (m_caches.find(key) != m_caches.end()) {
			update(key);
            m_caches[key].first = value;
            return;
        }
        
        if (m_caches.size() == m_capacity) {
            int lruKey = m_rukeys.back();
            m_caches.erase(lruKey);
            m_rukeys.pop_back();
        }
		update(key);
        m_caches[key].first = value;
    }
private:
	void update(int key) {
		if (m_caches.find(key) != m_caches.end()) {
			m_rukeys.erase(m_caches[key].second);
		}
        m_rukeys.push_front(key);
        m_caches[key].second = m_rukeys.begin();
	}
	int m_capacity;
    list<int> m_rukeys;    // recently used keys
    map<int, pair<int, list<int>::iterator> > m_caches;
};