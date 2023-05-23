class Solution {
public:
    int maxScore(int l,int r,int i,vector<int>& nums, vector<int>& multipliers,vector<vector<int>> &dp)
    {
        if(i==multipliers.size())
            return 0;
        if(dp[l][i]!=-1) return dp[l][i];
        int left=nums[l]*multipliers[i]+maxScore(l+1,r,i+1,nums,multipliers,dp);
        int right=nums[r]*multipliers[i]+maxScore(l,r-1,i+1,nums,multipliers,dp);
        return dp[l][i]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(multipliers.size()+1,-1));
        return maxScore(0,nums.size()-1,0,nums,multipliers,dp);
    }
};