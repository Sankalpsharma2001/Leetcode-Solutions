#define ll long long

class Solution {
public:
     vector<int> primes;
     ll dp[1001][1 << 11];
     ll mod;
    ll getMask(ll num)
    {
        ll mask=0;
        for(int i=0;i<10;i++)
        {
            int c=0;
            while(num%primes[i]==0)
            {
                c++;
                num/=primes[i];
            }
            if(c>1)
                return -1;
            if(c==1)
      mask=mask|(1 << (i + 1)); // i + 1 because the for i == 0 product 1 has already been taken
            
        }
        return mask;
    }
    int dfs(vector<int> &nums,int idx,int mask)
    {
        if(idx>=nums.size()) return 1;
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        ll m=getMask(nums[idx]);
        ll ans=dfs(nums,idx+1,mask);
          //if there's no common bit, that is , square free
        if((m&mask)==0)
        {
            ans=(ans+dfs(nums,idx+1,mask|m)%mod)%mod;
            
        }
        return dp[idx][mask]=ans%mod;
        
    }
    int squareFreeSubsets(vector<int>& nums) {
         mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        return dfs(nums,0,1)-1;
    }
};