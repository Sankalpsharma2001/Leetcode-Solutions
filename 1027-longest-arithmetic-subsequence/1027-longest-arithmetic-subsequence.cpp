class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(1001,0));
        if(n<=2) return n;
        int ans=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int dif=nums[j]-nums[i]+500;
                dp[i][dif]=max(dp[j][dif]+1,2);
                ans=max(ans,dp[i][dif]);
            }
        }
        return ans;
    }
};