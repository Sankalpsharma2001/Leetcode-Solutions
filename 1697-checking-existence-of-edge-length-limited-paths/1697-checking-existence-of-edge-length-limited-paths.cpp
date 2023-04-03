class Solution {
public:
    vector<int> parent,rank;
    int find(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=find(parent[node]);
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](auto &a,auto &b){ return a[2]<b[2];});
        sort(edgeList.begin(),edgeList.end(),[](auto &a,auto &b){return a[2]<b[2];});
        
        vector<bool> ans(queries.size());
        int i=0;
        for(auto &q:queries)
        {
            while(i<edgeList.size() && edgeList[i][2]<q[2])
            {
                merge(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            ans[q[3]]=find(q[0])==find(q[1]);
        }
        return ans;
        
        
    }
};