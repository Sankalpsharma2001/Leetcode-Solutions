#define ll long long
class Solution {
public:
    ll dp[101][21][101];
    ll solve(int i,int pre,int c,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        if(c>target)
            return INT_MAX;
        if(i==m)
        {
            return (c==target)?0:INT_MAX;
        }
        if(dp[i][pre][c]!=-1) return dp[i][pre][c];
        
            ll temp=INT_MAX;
            if(houses[i]==0)
            {
              for(int j=0;j<n;j++)
              {
                  temp=min(temp,cost[i][j]+solve(i+1,j+1,(j+1==pre)?c:c+1,houses,cost,m,n,target));
              }
                
            }
            else
            {
                temp=min(temp,solve(i+1,houses[i],(houses[i]==pre)?c:c+1,houses,cost,m,n,target));
            }
          
        
        return dp[i][pre][c]=temp;
    
            }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        
        ll ans=solve(0,0,0,houses,cost,m,n,target);
        return (ans==INT_MAX)?-1:ans;
    }
};