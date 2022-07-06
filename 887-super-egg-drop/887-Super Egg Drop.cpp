#define ll long long
class Solution {
public:
    ll solve(int k,int n,vector<vector<ll>> &dp)
    {
        if(k==1)
            return n;
        if(n==0 || n==1)
            return n;
        
        if(dp[k][n]!=-1)
            return dp[k][n];
        ll mn=INT_MAX;
        int low=1,high=n;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            int down=solve(k-1,mid-1,dp);
            int up=solve(k,n-mid,dp);
            ll temp=1+max(up,down);
            if(up>down)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mn=min(mn,temp);
        }
        // for(int i=1;i<=n;i++)
        // {
        //     ll a;
        //     ll b;
        //     if(dp[k-1][i-1]!=-1)
        //     {a=dp[k-1][i-1];
        //     }
        //     else
        //     {a=solve(k-1,i-1,dp);
        //         dp[k-1][i-1]=a;
        //     }  
        //     if(dp[k][n-i]!=-1)
        //     {
        //         b=dp[k][n-i];
        //     }
        //     else
        //     {
        //         b=solve(k,n-i,dp);
        //         dp[k][n-i]=b;
        //     }
        //     ll temp=1+max(a,b);
        //     // ll temp=1+max(solve(k-1,i-1,dp),solve(k,n-i,dp));
        //     mn=min(mn,temp);
        // }
        return dp[k][n]=mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<ll>> dp(k+1,vector<ll>(n+1,-1));
        return solve(k,n,dp);
    }
};
