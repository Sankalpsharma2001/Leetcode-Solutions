class Solution {
public:
    int N=10001;
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(N,0);
        vector<int> dp(N,0);
       
       for(auto &x:nums)
           sum[x]+=x;
        dp[0]=0;
        dp[1]=sum[1];
        for(int i=2;i<N;i++)
        {
            int inc=sum[i]+dp[i-2];
            int exc=dp[i-1];
            dp[i]=max(inc,exc);
        }
        return dp[N-1];
    }
};