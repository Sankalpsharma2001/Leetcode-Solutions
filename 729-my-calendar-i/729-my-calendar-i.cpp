class MyCalendar {
public:
   vector<pair<int,int>> p;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       for(auto x:p)
       {
           if(x.first<start and x.second>start)
               return false;
           if(x.first<end and x.second>end)
               return false;
           if(x.first>=start and x.second<end) return false;
           
           if(x.first>=start and x.second<=end) return false;
           
       }
        p.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */