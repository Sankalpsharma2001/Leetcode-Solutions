#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        ll n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<ll,ll> mp;
        vector<ll> dp(n,1);
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int t=arr[i]/arr[j];
                    if(mp.count(t))
                    {
                        dp[i]+=(dp[j]*dp[mp[t]])%mod;
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=dp[i]%mod;
        }
        return ans%mod;
        
    }
};