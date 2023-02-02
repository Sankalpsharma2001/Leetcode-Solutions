class Solution {
public:
    int ans,c;
    bool flag;
    void dfs(int node,int par,vector<int> &vis,vector<int> &dvis,vector<vector<int>> &adj,vector<int> & count)
    {
        vis[node]=1;
       dvis[node]=1;
        if(par==-1)
            count[node]=1;
        else
        count[node]=count[par]+1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
           
            // count[it]=c;
            dfs(it,node,vis,dvis,adj,count);
           
        }
        else if(dvis[it]==1)
        {
           
            ans=max(ans,count[node]-count[it]+1);
            flag=true;
            
        }
    }
    dvis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        flag=false;
        ans=0;
        vector<int> count(n,0),vis(n,0),dvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c=0;
                count.clear();
                dfs(i,-1,vis,dvis,adj,count);
            }
        }
        return flag==false?-1:ans;
    }
};