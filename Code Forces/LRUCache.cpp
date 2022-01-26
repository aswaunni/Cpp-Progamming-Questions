/*
Design a data structure that works like a LRU(Least Recently Used) Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be intitialized.

Input:
cap = 2
Q = 8
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
Output: 5 -1
*/

class LRUCache
{
    private:
        int m_cap;
        list<pair<int, int>> dq;
        unordered_map<int, list<pair<int, int>>::iterator> m_map;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    : m_cap(cap)
    {
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (m_map.find(key) == m_map.end())
            return -1;
        pair<int, int> it = *m_map[key];
        dq.erase(m_map[key]);
        dq.push_front(it);
        m_map[key] = dq.begin(); 
        return it.second;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (m_map.find(key) != m_map.end())
            dq.erase(m_map[key]);  
        else {
            if (dq.size() == m_cap) {
                m_map.erase(dq.back().first);
                dq.pop_back();
            }
        }  
        dq.push_front({key, value});
        m_map[key] = dq.begin(); 
    }

};

