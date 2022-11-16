class DisjointSet{
    public:
    vector<int> parent,size,rank;
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
    }
    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int a,int b)
    {
        a=findParent(a);
        b=findParent(b);
         if(a==b) return;
        if(rank[a]<rank[b])
        {
            parent[a]=b;
            
        }
        else if(rank[a]>rank[b])
        {
            parent[b]=a;
        }
        else
        {
            parent[b]=a;
            rank[a]++;
        }
        
    }
    void unionBySize(int a,int b)
    {
         a=findParent(a);
        b=findParent(b);
        if(a==b) return;
        if(size[a]<size[b])
        {
            parent[a]=b;
            size[b]+=size[a];
        }
        else
        {
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DisjointSet ds(n+1);
        for(int i=threshold+1;i<=n;i++)
        {
            int m=1;
            while(i*m<=n)
            {
                ds.unionBySize(i,i*m);
                m++;
            }
        }
        vector<bool> ans;
        for(auto &it:queries)
        {
            bool t=ds.findParent(it[0])==ds.findParent(it[1]);
            ans.push_back(t);
        }
        return ans;
    }
};