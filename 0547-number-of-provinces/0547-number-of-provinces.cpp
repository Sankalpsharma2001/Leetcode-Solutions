class DisjointSet{
    public:
    vector<int> parent,rank;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=findParent(parent[x]);
    }
    void unionByRank(int u,int v)
    {
        u=findParent(u);
        v=findParent(v);
        if(u==v) return;
        if(rank[u]<rank[v])
        {
         parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }

    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
        DisjointSet d(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    d.unionByRank(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i==d.parent[i]) ans++;
        }
        return ans;
    }
};