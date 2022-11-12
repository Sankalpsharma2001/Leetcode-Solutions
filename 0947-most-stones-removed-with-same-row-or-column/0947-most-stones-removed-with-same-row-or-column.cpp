class DisjointSet{
public: 
vector<int> parent,rank,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
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
    int removeStones(vector<vector<int>>& stones) {
         int mxrow=0,mxcol=0;
        int n=stones.size();
        for(int i=0;i<stones.size();i++)
        {
            mxrow=max(mxrow,stones[i][0]);
            mxcol=max(mxcol,stones[i][1]);
        }
         DisjointSet ds(mxrow+mxcol+2); 
         unordered_map<int,int> m;
         for(auto &it:stones)
         {
             int nodeRow=it[0];
             int nodeCol=it[1]+mxrow+1;
             ds.unionBySize(nodeRow,nodeCol);
             m[nodeRow]=1;
             m[nodeCol]=1;
         }
         int cnt=0;
         for(auto &it:m)
         {
             if(ds.findParent(it.first)==it.first)
             {
                 cnt++;
             }
         }
         return n-cnt;
    }
};