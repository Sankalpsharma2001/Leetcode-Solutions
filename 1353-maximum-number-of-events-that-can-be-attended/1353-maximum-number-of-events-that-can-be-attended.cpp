class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
           int n=events.size();
         priority_queue<int,vector<int>,greater<int>> pq;
        
        sort(events.begin(),events.end());
        int ans=0;
        int i=0;
         for(int d=1;d<=100000;d++)
        {
          
            while(!pq.empty()&&pq.top()<d)
            {
                pq.pop();
            }
             
            while(i<n && events[i][0]==d  )
            {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
            
            if(pq.empty()&&i==n)
                break;
        }
        return ans;
        
        
    }
};