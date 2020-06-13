// 题目描述
// 146. LRU缓存机制
// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
// 你是否可以在 O(1) 时间复杂度内完成这两种操作？

class LRUCache {
public:
    LRUCache(int capacity) : m_Capacity(capacity) {
        
    }
    
    int get(int key) {
        auto itr = m_MapItr.find(key);
        if (itr == m_MapItr.end()) return -1;
        auto pr = *(itr->second);
        m_Queue.erase(itr->second);
        m_Queue.push_front(pr);
        m_MapItr[key] = m_Queue.begin();
        return pr.second;
    }
    
    void put(int key, int value) {
        auto itr = m_MapItr.find(key);
        if (itr == m_MapItr.end())
        {
            if (m_Queue.size() == m_Capacity)
            {
                m_MapItr.erase(m_Queue.back().first);
                m_Queue.pop_back();
            }
        }
        else
        {
            m_Queue.erase(itr->second);
        }
        m_Queue.push_front(std::make_pair(key, value));
        m_MapItr[key] = m_Queue.begin();;
    }
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_MapItr;
    std::list<std::pair<int, int>> m_Queue;
    int m_Capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */