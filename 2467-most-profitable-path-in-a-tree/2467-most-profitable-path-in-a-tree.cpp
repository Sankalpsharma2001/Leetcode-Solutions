class Solution {
public:
     vector<int> parent,dis;
    void dfs(int node, vector<vector<int>> &adj,int par=0,int d=0)
    {
        dis[node]=d;
        parent[node]=par;
        for(auto &it:adj[node])
        {
            if(it!=par)
            {
                dfs(it,adj,node,d+1);
            }
        }
    }
    set<int> s;
    int res=INT_MIN;
    void dfs1(int node,vector<int> &amount,vector<vector<int>> &adj,int &ans)
    {
        s.insert(node);
        ans+=amount[node];
        int trav=0;
        for(auto &it:adj[node])
        {
            if(s.find(it)==s.end())
            {
                trav++;
                dfs1(it,amount,adj,ans);
            }
        }
        if(trav==0)
            res=max(res,ans);
        ans-=amount[node];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // alice want to go leaf and bob to reach node 0
        int n=amount.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        parent.resize(n);
        dis.resize(n);
        dfs(0,adj);
        int cur=bob;
        int disBob=0;
        while(cur!=0)
        {
            if(dis[cur]>disBob)
            {
                amount[cur]=0;
            }
            else if(dis[cur]==disBob)
            {
                amount[cur]/=2;
            }
            cur=parent[cur];
            
            disBob++;
        }
        //calculate alice cost from 0 to leaf node
        int ans=0;
        dfs1(0,amount,adj,ans);
       
        return res;
        
    }
};