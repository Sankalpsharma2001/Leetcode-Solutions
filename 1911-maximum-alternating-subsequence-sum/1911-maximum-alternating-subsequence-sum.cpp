#define ll long long
class Solution {
public:
    ll sum(int i,int isPos,vector<int> &nums,vector<vector<ll>> &dp)
    {
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i][isPos]!=-1) return dp[i][isPos];
        if(isPos==1)
        {
            ll a=sum(i+1,isPos,nums,dp);
            ll b=nums[i]+sum(i+1,!isPos,nums,dp);
            return dp[i][isPos]=max(a,b);
            
        }
        // else
         ll a=sum(i+1,isPos,nums,dp);
            ll b=-nums[i]+sum(i+1,!isPos,nums,dp);
            return dp[i][isPos]=max(a,b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
        return sum(0,1,nums,dp);
    }
};