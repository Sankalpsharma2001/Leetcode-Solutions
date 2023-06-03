class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key,int value)
        {
            this->key=key;
            this->val=value;
            prev=NULL;
            next=NULL;
        }
    };
      Node *head=new Node(-1,-1);
      Node *tail=new Node(-1,-1);
      int cap;
      unordered_map<int,Node*> m;
    LRUCache(int capacity) {
       cap=capacity;
        head->next=tail;
        tail->prev=head;   
    }
    void deleteNode(Node *newNode)
    {
        Node *prevdel=newNode->prev;
        Node *nextdel=newNode->next;
        prevdel->next=nextdel;
        nextdel->prev=prevdel;
    }
    void addNode(Node *newNode)
    {
        Node *t=head->next;
        newNode->next=t;
        newNode->prev=head;
        head->next=newNode;
        t->prev=newNode;
    }
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            Node *temp=m[key];
            int value=temp->val;
            m.erase(key);
            deleteNode(temp);
            addNode(temp);
            m[key]=head->next;
          return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
          Node *exist=m[key];
            m.erase(key);
            deleteNode(exist);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key]=head->next;    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */