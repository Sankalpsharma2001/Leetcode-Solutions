class BrowserHistory {
public:
    class Node{
        public:
        string data;
        Node *pre,*next;
        Node(string x)
        {
            this->data=x;
            this->pre=NULL;
            this->next=NULL;
        }
    };
    Node *head;
    BrowserHistory(string homepage) {
        head=new Node(homepage);
    }
    
    void visit(string url) {
        Node *x=new Node(url);
        head->next=x;
        x->pre=head;
        head=x;
        head->next=NULL;
    }
    
    string back(int steps) {
        while(steps--)
        {
            if(head->pre)
            {
                head=head->pre;
            }
            else break;
        }
        return head->data;
    }
    
    string forward(int steps) {
        while(steps--)
        {
            if(head->next)
            {
                head=head->next;
            }
            else break;
        }
        return head->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */