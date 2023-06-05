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
    bool isValid(int &x,int &y,int &n,int &m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
          int n = grid.size(), m = grid[0].size();
        int k=queries.size();
        vector<int> ans(k);
        
        vector<vector<int>> nodes;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                nodes.push_back({grid[i][j],i,j});
            }
        }
        sort(nodes.begin(), nodes.end());
        vector<pair<int,int>> q;
        for(int i=0;i<k;i++)
        {
            q.push_back(make_pair(queries[i],i));
        }
        sort(q.begin(),q.end());
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
         vector<vector<bool>> visited(n, vector<bool>(m, false));

         DisjointSet ds(n*m+1);
         int i=0;
        for(auto &it:q)
        {
            while(i<n*m && nodes[i][0]<it.first)
            {
                int x=nodes[i][1],y=nodes[i][2];
                visited[x][y]=1;
                for(int dir=0;dir<4;dir++)
                {
                    int X=x+dx[dir];
                    int Y=y+dy[dir];
                    if(isValid(X,Y,n,m) && visited[X][Y])
                    {
                        int u=x*m+y;
                        int v=X*m+Y;
                        ds.unionBySize(u,v);
                    }
                }
                i++;
            }
            if(visited[0][0])
            {
                ans[it.second]=ds.size[ds.findParent(0)];
            }
        }
        
        return ans;
        
    }
};