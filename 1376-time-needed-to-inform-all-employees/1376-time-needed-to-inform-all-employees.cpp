class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
     
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1) continue;
           
            adj[manager[i]].push_back(i);
        }
          queue<int> q;
        q.push(headID);
        vector<int> time(n,0);
        time[headID]=0;
         while(!q.empty())
         {
             auto f=q.front();
            q.pop();
             for(auto &it:adj[f])
             {
                q.push(it);
                 time[it]=time[f]+informTime[f];
             }
         }
        return *max_element(time.begin(),time.end());
    }
};