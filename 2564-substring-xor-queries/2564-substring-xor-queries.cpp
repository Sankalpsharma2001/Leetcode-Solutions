#define pii pair<int,int>
#define ll long long
#define f first
#define s second
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        int n=s.size();
         unordered_map<ll,pii> m;
         for(int i=0;i<n;i++)
         {
             if(s[i]=='0')
             {
                 if(!m.count(0))
                 {
                     m[0]=make_pair(i,i);
                 }
                 continue;
             }
             ll num=0;
             for(int j=i;j<=min(n-1,i+32);j++)
             {
                 num=(num<<1)+s[j]-'0';
                 if(!m.count(num))
                 {
                     m[num]=make_pair(i,j);
                 }
                 
             }
         }
        for(int i=0;i<queries.size();i++)
        {
            ll l=queries[i][0],r=queries[i][1];
            ll x=l^r;
            if(m.count(x))
            {
                ans.push_back({m[x].f,m[x].s});
            }
            else
            {
                ans.push_back({-1,-1});
            }
        }
        return ans;
        
    }
};