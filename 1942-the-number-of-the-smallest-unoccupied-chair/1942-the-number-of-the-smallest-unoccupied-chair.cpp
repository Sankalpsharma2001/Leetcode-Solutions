class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
      int n=times.size();
           int target = times[targetFriend][0];
        sort(times.begin(),times.end());
    
        priority_queue<int,vector<int>,greater<int>> chair;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> leave;
      for(int i=0;i<n;i++)
      {
          chair.push(i);
      }
        
        for(int i=0;i<n;i++)
        {
            int a=times[i][0],d=times[i][1];
            while(!leave.empty() && leave.top().first<=a)
            {
                chair.push(leave.top().second);
                leave.pop();
            }
            int c=chair.top();
            chair.pop();
            leave.push({d,c});
            if(target==a)
            {return c;}
            
        }
        return -1;
        
    }
};