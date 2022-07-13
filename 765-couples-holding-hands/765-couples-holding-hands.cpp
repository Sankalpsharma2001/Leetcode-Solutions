class Solution {
public:
    vector<int> parent;
    int find(int a)
    {
        if(a==parent[a])
            return a;
        return parent[a]=find(parent[a]);
    }
    bool Union(int a,int b)
    {
        int u=find(a);
        int v=find(b);
        if(u==v)
            return false;
        parent[v]=u;
            return true;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        parent.resize(n);
        for(int i=0;i<n;i+=2)
        {
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            if(Union(i,i+1))
                ans++;
        }
        return ans;
    }
};