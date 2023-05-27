class Solution {
public:
    int win(int st,int end,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(st==end)
            return nums[st];
        if(dp[st][end]!=-1) return dp[st][end];
        int left=nums[st]-win(st+1,end,nums,dp);
        int right=nums[end]-win(st,end-1,nums,dp);
        return dp[st][end]=max(left,right);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return win(0,n-1,nums,dp)>=0;
    }
};