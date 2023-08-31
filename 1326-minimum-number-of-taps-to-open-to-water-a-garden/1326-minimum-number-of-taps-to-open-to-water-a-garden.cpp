class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            dp[left]=max(dp[left],right);
        }
        int ans=0;
        int mxr=0,pos=0;
        for(int i=0;i<n;i++)
        {
            mxr=max(dp[i],mxr);
            if(i==pos)
            {
                pos=mxr;
                ans++;
            }
        }
        if(pos>=n)
        return ans;
        return -1;
    }
};