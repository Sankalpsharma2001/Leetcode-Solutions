class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int a,int b)
    {
        a=find(a);
        b=find(b);
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
            parent[a]=b;
             rank[b]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<int>> r,c;
        rank.resize(stones.size()+1);
        for(int i=0;i<stones.size();i++)
        {
            parent.push_back(i);
            rank[i]=0;
        }
          for(int i=0;i<stones.size();i++)
        {
            r[stones[i][0]].push_back(i);
            c[stones[i][1]].push_back(i);
        }
        for(int i=0;i<stones.size();i++)
        {
            for(auto x:r[stones[i][0]])
                Union(i,x);
            for(auto y:c[stones[i][1]])
                Union(i,y);
        }
        unordered_set<int> s;
        for(auto x:parent)
        {
            s.insert(find(x));
        }
        return stones.size()-s.size();
        
    }
};