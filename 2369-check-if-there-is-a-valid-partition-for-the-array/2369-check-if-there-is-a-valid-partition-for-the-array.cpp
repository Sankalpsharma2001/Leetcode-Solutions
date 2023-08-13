class Solution {
public:
    int solve(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i==nums.size()) return dp[i]=true;
        if(dp[i]!=-1) return dp[i];
        if(i+1<nums.size() && nums[i]==nums[i+1])
        {
            if(solve(i+2,nums,dp)) return dp[i]=true;
            if(i+2<nums.size() && nums[i]==nums[i+2])
            {
                if(solve(i+3,nums,dp)) return dp[i]=true;
            }
        }
        if(i+2<nums.size() && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1)
        {
            if(solve(i+3,nums,dp)) return dp[i]=true;
        }
         return dp[i]=false;   
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,nums,dp);
    }
};