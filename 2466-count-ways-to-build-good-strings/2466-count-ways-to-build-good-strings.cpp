#define ll long long
class Solution {
public:
    int mod=1e9+7;
    ll count(int target,int zero,int one,vector<ll> &dp)
    {
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1)
            return dp[target];
        ll s=0;
        s=(s%mod+count(target-zero,zero,one,dp)%mod)%mod;
        s=(s%mod+count(target-one,zero,one,dp)%mod)%mod;
        return dp[target]=s%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // vector<ll> dp(high+5,-1);
        // ll ans=0;
        // for(int i=low;i<=high;i++)
        // {
        //     ans=(ans%mod+count(i,zero,one,dp)%mod)%mod;
        // }
        // return ans%mod;
        // Time Complexity is O(N)
         vector<int> dp(high+1, 0);
        dp[0]=1;
        int mod= 1e9+7;
        for(int i=1; i<=high; i++){
            if( i-zero>=0)
                dp[i] = (dp[i] + dp[i-zero])%mod;
            if( i-one>=0)
                dp[i]= (dp[i] + dp[i-one])%mod;

        }
        int ans=0;
        for(int i=low; i<=high; i++)
            ans=(ans + dp[i])%mod;
   
        return ans;
    }
};