class Solution {
public:
    static bool com(vector<int> &a,vector<int> &b)
    {
        return a[0]>b[0];
    }
    int findParent(int u,vector<int> &parent)
    {
        if(u==parent[u])
            return u;
        return parent[u]=findParent(parent[u],parent);
    }
    bool merge(int u,int v,vector<int> &parent,vector<int> &Rank)
    {
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u!=v)
        {
            if(Rank[u]<Rank[v])
            {
                parent[u]=v;
                
            }
            else if(Rank[v]<Rank[u])
            {
                parent[v]=u;
            }
            else
            {
                parent[v]=u;
                Rank[u]++;
            }
            return true;
        }
        return false; // already join
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),com);
        vector<int> parentAlice(n+1),parentBob(n+1),rankAlice(n+1,1),rankBob(n+1,1);
        for(int i=0;i<n+1;i++)
        {
            parentAlice[i]=i;
            parentBob[i]=i;
            rankAlice[i]=1;
            rankBob[i]=1;
        }
        int x=0,y=0;
        int removeEdge=0;
        for(auto &edge:edges)
        {
            if(edge[0]==3)
            {
                bool a=merge(edge[1],edge[2],parentAlice,rankAlice);
                bool b=merge(edge[1],edge[2],parentBob,rankBob);
                if(a)
                    x++;
                if(b)
                    y++;
                if(!a && !b)
                    removeEdge++;
                
            }
            else if(edge[0]==1)
            {
                bool a=merge(edge[1],edge[2],parentAlice,rankAlice);
                if(a)
                    x++;
                else
                    removeEdge++;
            }
            else
            {
               bool b=merge(edge[1],edge[2],parentBob,rankBob);
                if(b)
                    y++;
                else
                    removeEdge++;
            }
        }
        if(x!=n-1 || y!=n-1)
        {
            return -1;
        }
        return removeEdge;
    }
};