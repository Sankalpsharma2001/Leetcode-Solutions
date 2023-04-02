class Solution {
public:
    vector<int> parent,rank;
    int find(int u)
    {
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void merge(int u,int v)
    {
        u=find(u);
        v=find(v);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
            
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<vector<int>> adj(n+1);
        map<int,vector<int>> val;
        rank.resize(n);
        parent.resize(n);
        int ans=0;
        for(int i=0;i<n;i++)         
        {
            rank[i]=0;
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            val[vals[i]].push_back(i);
        }
        
        for(auto &it:edges)
        {
            if(vals[it[0]]>=vals[it[1]])
            {
                adj[it[0]].push_back(it[1]);
            }
            else
            {
                adj[it[1]].push_back(it[0]);
            }
        }
        
        for(auto &it:val)
        {
            for(auto &node:it.second)
            {
                for(auto &v:adj[node])
                {
                    merge(node,v);
                }
            }
            unordered_map<int,int> group;
            for(auto & v:it.second)
            {
                group[find(v)]++;
            }
            ans+=it.second.size();
            for(auto &it:group)
            {
                ans+=(it.second*(it.second-1))/2;
            }
            
            
        }
        
         return ans;
        
    }
   
};