class Solution {
public:
    int dfs(int node,vector<vector<int>> &adj,string &s,int &ans)
    {
        if(adj[node].empty()) return 1;
        int mx1=0,mx2=0;
        for(auto &it:adj[node])
        {
            int len=dfs(it,adj,s,ans);
            ans=max(ans,len);
            if(s[it]==s[node]) continue;
            if(len>mx1)
            {
                mx2=mx1;
                mx1=len;
            }
            else
            {
                mx2=max(mx2,len);
            }
        }
        ans=max(ans,mx1+mx2+1);
        return 1+mx1;
    }
    int longestPath(vector<int>& parent, string s) {
      vector<vector<int>> adj(parent.size());
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==-1) continue;
           
           adj[parent[i]].push_back(i);
        }
        int ans=1;
        dfs(0,adj,s,ans);
        return ans;
    }
};