class Solution {
public:
    vector<int> kahn(vector<vector<int>>& v,int k)
    {   vector<int> indegree(k+1,0);
        vector<int> adj[k+1];
        for(auto &it:v)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
     for(int i=1;i<=k;i++)
     {
         if(indegree[i]==0)
             q.push(i);
     }
     vector<int> topo;
     while(!q.empty())
     {
         auto f=q.front();
         q.pop();
         topo.push_back(f);
         for(auto &it:adj[f])
         {
             indegree[it]--;
             if(indegree[it]==0)
                 q.push(it);
         }
     }
      return topo;  
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
    
        vector<int> r=kahn(row,k);
        vector<int> c=kahn(col,k);
        if(r.size()!=k) return {};
        if(c.size()!=k) return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
       vector<pair<int,int>> p(k);
        for(int i=0;i<r.size();i++)
        {
            p[r[i]-1].first=i;
            p[c[i]-1].second=i;
        }
        
        for(int i=0;i<k;i++)
        {
            ans[p[i].first][p[i].second]=i+1;
        }
        return ans;
    }
};