class UnionFind{
  private:
   vector<int> parent,rank;  
  public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
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
};
class Solution {
public:
    bool check(string &a,string &b)
    {
        int c=0;
        
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i]) c++;
            if(c>2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        UnionFind dsu(n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(strs[i],strs[j]) && dsu.find(i)!=dsu.find(j))
                {
                    dsu.merge(i,j);
                    cnt++;
                }
            }
        }
        return n-cnt;
    }
};