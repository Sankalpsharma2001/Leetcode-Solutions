class TopVotedCandidate {
public:
  
    vector<int> t,lead;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n=persons.size();
        vector<int> cnt(n,0);
        t=times;
        int curMax=0;
        for(int i=0;i<n;i++)
        {
          cnt[persons[i]]++;
            if(cnt[persons[i]]>=cnt[curMax])
            {
                curMax=persons[i];
               
            }
            lead.push_back(curMax);
        }
    }
    
    int q(int time) {
      auto it=upper_bound(t.begin(),t.end(),time)-t.begin();
        
        return lead[it-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */