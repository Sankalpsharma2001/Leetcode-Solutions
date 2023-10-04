class MyHashMap {
public:
    int sz=1000000;
    vector<vector<pair<int,int>>> m;
    MyHashMap() {
        m.resize(sz);
    }
    
    void put(int key, int value) {
        int index=key%sz;
        vector<pair<int,int>> &v=m[index];
         vector<pair<int,int>> ::iterator i;
        for( i=v.begin();i!=v.end();i++)
        {
            if(i->first==key)
            {
                i->second=value;
                return;
            }
        }
        v.push_back(make_pair(key,value));
        
    }
    
    int get(int key) {
        int index=key%sz;
        vector<pair<int,int>> &v=m[index];
        vector<pair<int,int>> ::iterator i;
        for( i=v.begin();i!=v.end();i++)
        {
            if(i->first==key)
                return i->second;
        }
        return -1;
    }
    
    void remove(int key) {
         int index=key%sz;
        vector<pair<int,int>> &v=m[index];
         vector<pair<int,int>> ::iterator i;
        for( i=v.begin();i!=v.end();i++)
        {
            if(i->first==key)
            {v.erase(i);
            return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */