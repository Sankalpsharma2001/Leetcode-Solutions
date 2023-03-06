#define ll long long
class Solution {
public:
    ll mypow(ll a, ll b, ll m) {
a %= m;
ll res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
    vector<int> parent,Rank;
    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(Rank[x]<Rank[y])
        {
            parent[x]=y;
        }
        else if(Rank[y]<Rank[x])
        {
            parent[y]=x;
        }
        else
        {
            parent[y]=x;
            Rank[x]++;
        }
    }
    int countWays(vector<vector<int>>& ranges) {
    int n=ranges.size();
        sort(ranges.begin(),ranges.end());
        int mod=1e9+7;
        int x=-1,y=-1;
        parent.resize(n+1);
        Rank.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            Rank[i]=0;
        }
        for(int i=0;i<ranges.size();i++)
        {
            if(x==-1 && y==-1)
            {
                x=ranges[0][0],y=ranges[0][1];
            }
            else
            {
                if(ranges[i][0]>=x && ranges[i][0]<=y)
                {
                    merge(i,i-1);
                    y=max(ranges[i][1],y);
                }
                else
                {
                    x=ranges[i][0],y=ranges[i][1];
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i) c++;
        }
        long long ans=1;
       for(int i=1;i<=c;i++)
       {
           ans=((ans%mod)*2)%mod;
       }
        return ans;
//         int x=ranges[0][1];
      
//         vector<vector<int>> v;
//         for(int i=0;i<ranges.size();i++)
//         {
            
//             if(v.size()>0)
//             int prev=v[v.size()-1][1];
//             if(v.size()==0 || v.back()[1]<ranges[i][0])
//             {
//                 v.push_back(ranges[i]);
//             }
//             else
//             {
//                 v[v.size()-1][1]=max(ranges[i][1],v[v.size()-1][1]);
//             }
//         }
//     long long res=mypow(2,v.size(),mod);
//         return res;
    }
};