#define ll long long
class Solution {
public:
   const int mod=1e9+7;
    int dp[15][1<<15];
    ll solve(int prev,int cnt,int mask,vector<int> &nums)
    {
        int n=nums.size();
        if(cnt==nums.size()) return 1;
        if(dp[prev][mask]!=-1) return dp[prev][mask];
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if((mask & (1<<i))==0)
            {
                if((nums[i]%nums[prev]==0) || (nums[prev]%nums[i]==0))
                {
                    ans=(ans%mod+solve(i,cnt+1,mask|(1<<i),nums)%mod)%mod;
                    ans%=mod;
                }
            }
        }
        return dp[prev][mask]=ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            ans=(ans%mod+solve(i,1,1<<i,nums)%mod)%mod;
            ans%=mod;
        }
        return ans;
    }
};