class Solution {
public:
    void dfs(vector<int> &vis,vector<int> &ind,int cur,vector<vector<int>> &adj)
    {
        vis[cur]=1;
        ind.push_back(cur);
        for(auto x:adj[cur])
        {
            if(!vis[x])
                dfs(vis,ind,x,adj);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
     
         int n = s.size();
        
        vector<vector<int>> adj(n);
        for(auto i: pairs) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int> ind;
                dfs(vis,ind,i,adj);
                string t="";
                for(auto x:ind)
                    t+=s[x];
                sort(t.begin(),t.end());
                sort(ind.begin(),ind.end());
                for(int j=0;j<ind.size();j++)
                {
                    s[ind[j]]=t[j];
                }
            }
        }
        return s;
    }
};