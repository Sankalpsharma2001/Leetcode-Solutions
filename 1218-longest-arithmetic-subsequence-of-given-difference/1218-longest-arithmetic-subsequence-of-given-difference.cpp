class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        vector<int> dp(1e5+1,0);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            dp[arr[i]+20000]=1+dp[arr[i]+20000-difference];
            ans=max(ans,dp[arr[i]+20000]);
        }
        return ans;
    }
};