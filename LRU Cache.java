public class LRUCache {
    class LinkedList {
        LinkedList(int k, int v) {
        	key = k;
            value = v;
            prev = null;
            next = null;
        }
        int key;
        int value;
        LinkedList prev;
        LinkedList next;
    }
    private int m_capacity;
    private Map<Integer, LinkedList> m_cache;
    LinkedList m_head;
    LinkedList m_tail;
    public LRUCache(int capacity) {
        m_capacity = capacity;
        m_cache = new HashMap<Integer, LinkedList>();
        m_head = null;
        m_tail = null;
    }

    public int get(int key) {
        if (m_cache.containsKey(key)) {
            touch(key);
            return m_head.value;
        }
        return -1;
    }

    public void set(int key, int value) {
    	if (!m_cache.containsKey(key) && m_cache.size() == m_capacity) {
            // remove least used key
            LinkedList tail = m_tail.prev;
            m_cache.remove(m_tail.key);
            m_tail = tail;
        }
        touch(key);
        m_cache.get(key).value = value;
    }

    private void touch(int key) {
        if (!m_cache.containsKey(key)) {
            LinkedList node = new LinkedList(key, -1);
            m_cache.put(key, node);
            if (m_head == null) {
            	m_head = node;
            	m_tail = node;
            	return;
            }
            node.next = m_head;
            m_head.prev = node;
            m_head = node;
            return;
        }
        LinkedList node = m_cache.get(key);
        if (node == m_head)
        	return;
        if (node == m_tail) {
        	m_tail = node.prev;
        	m_tail.next = null;
        	node.prev = null;
        	node.next = m_head;
        	m_head.prev = node;
        	m_head = node;
        	return;
        }
    	// remove node
        if (node.prev != null)
            node.prev.next = node.next;
        if (node.next != null)
            node.next.prev = node.prev;

        // put node to the head
        node.prev = null;
        node.next = m_head;
        m_head.prev = node;
        m_head = node;
    }
}