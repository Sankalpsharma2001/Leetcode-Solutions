class MyCalendar {
public:
    map<int,int> m;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
     auto it=m.lower_bound(start);
        if(it!=m.end() and it->first<end) return false;
        if(it!=m.begin() and (--it)->second>start) return false;
        m.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */