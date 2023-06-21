#define ll long long
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size();i++)
        {
            p.push_back({nums[i],cost[i]});
        }
        sort(p.begin(),p.end());
        vector<ll> pre(n,0);
        pre[0]=p[0].second;
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+p[i].second;
        }
        ll c=0;
        for(int i=1;i<n;i++)
        {
            c+=1ll*(p[i].second*1ll*(p[i].first-p[0].first));
        }
        ll ans=c;
        for(int i=1;i<n;i++)
        {
            ll gap=p[i].first-p[i-1].first;
            c+=1ll*(pre[i-1]*gap);
            c-=1ll*(pre[n-1]-pre[i-1])*gap;
            ans=min(ans,c);
        }
        return ans;
        
        
    }
};