class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        auto start=*s.begin(),end=*s.begin();
        for(auto it=++s.begin();it!=s.end();it++)
        {
            int val=*it;
            if(val-end==1)
            {
              end=val;   
            }
            else
            {
                ans.push_back({start,end});
                start=end=val;
            }

         }
        ans.push_back({start,end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */