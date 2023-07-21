class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> dp(nums.size()+1,1),c(nums.size()+1,1);
        int mx=1;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                { 
                    if(dp[j]+1>dp[i])
                    {
                 dp[i]=dp[j]+1;
                        c[i]=c[j];
                    }
// this means there are more subsequences of same length ending at length lis[i]
                    else if(dp[j]+1==dp[i])
                    {
                        c[i]+=c[j];
                    }
                }
            }
            mx=max(mx,dp[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==mx)
                ans+=c[i];
        }
        return ans;
    }
};  