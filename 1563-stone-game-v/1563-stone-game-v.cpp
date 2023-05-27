#define ll long long
class Solution {
public:
    ll score(vector<ll> &pre,int st,int end,vector<vector<ll>> &dp)
    {
        if(st>=end) return 0;
        ll ans=0;
        if(dp[st][end]!=-1) return dp[st][end];
        for(int i=st;i<=end;i++)
        {
            ll leftSum=0,rightSum=0;
            if(st==0)
            {
                leftSum=pre[i];
            }
            else
                leftSum=pre[i]-pre[st-1];
            
            rightSum=pre[end]-pre[i];
            if(leftSum>rightSum)
            {
                ans=max(ans,rightSum+score(pre,i+1,end,dp));
            }
            else if(leftSum<rightSum)
            {
                ans=max(ans,leftSum+score(pre,st,i,dp));
            }
            else
            {
                ans=max({ans,leftSum+score(pre,st,i,dp),rightSum+score(pre,i+1,end,dp)});
            }
        }             
return dp[st][end]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        if(n==1) return 0;
        vector<ll> pre(n,0);
        pre[0]=stoneValue[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+stoneValue[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
        return score(pre,0,n-1,dp);
    }
};