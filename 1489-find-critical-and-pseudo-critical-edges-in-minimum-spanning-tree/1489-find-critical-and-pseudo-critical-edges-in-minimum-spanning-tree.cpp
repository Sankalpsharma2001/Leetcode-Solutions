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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
       
         vector<int> critical;
        vector<int> pseudoCritical;
        
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
             sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
          int mstwt = findMST(n, edges, -1, -1);
          
        for(int i=0;i<edges.size();i++)
        {
            if(mstwt<findMST(n,edges,i,-1))
            {
                critical.push_back(edges[i][3]);
            }
            else if(mstwt==findMST(n,edges,-1,i))
            {
               pseudoCritical.push_back(edges[i][3]);   
            }
        }
        
        vector<vector<int>> result;
        result.push_back(critical);
        result.push_back(pseudoCritical);
        return result;

    }
     int findMST(int n, vector<vector<int>>& edges, int block, int e) {
       DisjointSet ds(n+1);
         int w=0;
         if(e!=-1)
         {
             w+=edges[e][2];
             ds.unionBySize(edges[e][0],edges[e][1]);
         }
         
         for(int i=0;i<edges.size();i++)
         {
             if(i==block) continue;
             
             if(ds.findParent(edges[i][0])==ds.findParent(edges[i][1]))
             {
                 continue;
             }
             ds.unionBySize(edges[i][0],edges[i][1]);
             w+=edges[i][2];
             
         }
     
           for (int i = 0; i < n; i++) {
            if (ds.findParent(i) != ds.findParent(0))
                return INT_MAX;
        }

        return w;
     
     }
};