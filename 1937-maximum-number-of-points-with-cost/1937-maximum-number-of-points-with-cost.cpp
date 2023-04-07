#define ll long long
class Solution {
public:
    ll solve(vector<vector<int>>& points,int r,int prev,vector<vector<ll>> &dp)
    {
           int n=points.size(),m=points[0].size();
        if(r>=n)
        {
            return 0;
        }
        if(dp[r][prev]!=-1)
            return dp[r][prev];
        ll ans=0;
        for(int col=0;col<m;col++)
        {
            ll temp=points[r][col]-abs(col-prev)+solve(points,r+1,col,dp);
            ans=max(ans,temp);
        }
        return dp[r][prev]=ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(),m=points[0].size();
        vector<vector<ll>> dp(n,vector<ll>(m,-1));
       ll ans=0;
        // for(int i=0;i<m;i++)
        // {
        //     ans=max(ans,points[0][i]+solve(points,1,i,dp));
        // }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=points[0][i];
        }
         for (int i = 1; i < points.size(); ++i) {
            vector<long long> left_dp(m, -1);
            vector<long long> right_dp(m, -1);
            
            left_dp[0] = dp[i - 1][0];
            for (int k = 1; k < m; ++k) {
                left_dp[k] = max(left_dp[k - 1], dp[i - 1][k] + k);
            }
            
            right_dp.back() = dp[i - 1].back() - points[i].size() + 1;
            for (int k = m- 2; k >= 0; --k) {
                right_dp[k] = max(right_dp[k + 1], dp[i - 1][k] - k);
            }
            
            for (int j = 0; j < points[i].size(); ++j) {
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + points[i][j];
            }
        }
        
       for(int i=0;i<m;i++)
       {
           ans=max(ans,dp[n-1][i]);
       }
        
        return ans;
    }
};