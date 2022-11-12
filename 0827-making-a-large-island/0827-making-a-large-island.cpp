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
     private:
    bool isValid(int x,int y,int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
         int n=grid.size();
        DisjointSet ds(n*n);
        int ans=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==0) continue;
                int dx[]={1,-1,0,0};
                int dy[]={0,0,1,-1};
                for(int ind=0;ind<4;ind++)
                {
                    
                    int newr=dx[ind]+row;
                    int newc=dy[ind]+col;
                    if(isValid(newr,newc,n) && grid[newr][newc]==1)
                    {
                        int nodeNo=row*n+col;
                        int adjNodeNo=newr*n+newc;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1) continue;
                int dx[]={1,-1,0,0};
                int dy[]={0,0,1,-1};
                set<int> element;
                for(int ind=0;ind<4;ind++)
                {
                    int newr=dx[ind]+row;
                    int newc=dy[ind]+col;
                    if(isValid(newr,newc,n) && grid[newr][newc]==1)
                    {
                       
                        int adjNodeNo=newr*n+newc;
                        element.insert(ds.findParent(adjNodeNo));
                    }
                }
                int totalSize=0;
                for(auto it:element)
                {
                    totalSize+=ds.size[it];
                }
                ans=max(ans,totalSize+1);
            }
        }
        // when all element in grid is 1
        for(int i=0;i<n*n;i++)
        {
            ans=max(ans,ds.size[ds.findParent(i)]);
        }
        return ans;
    }
};