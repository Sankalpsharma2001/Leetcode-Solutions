class Solution {
public:
    int mod=1e9+7;
    int noOfWays(string &s,int index,int cnt,vector<vector<int>> &dp)
    {
        if(index>=s.size())
        {
            return cnt==2;
        }
        if(dp[index][cnt]!=-1) return dp[index][cnt];
        int ans=0;
        if(cnt==2)
        {
             if(s[index]=='P')
             {
                 ans=(ans+noOfWays(s,index+1,0,dp)+noOfWays(s,index+1,cnt,dp))%mod;
             }
            else
            {
                ans=(ans+noOfWays(s,index+1,1,dp))%mod;
            }
        }
        else
        {
            ans=(ans+noOfWays(s,index+1,cnt+(s[index]=='S'),dp))%mod;
        }
        return dp[index][cnt]=ans%mod;
    }
    int numberOfWays(string corridor) {
        int n=corridor.size();
      vector<vector<int>> dp(n+1,vector<int>(3,-1));    
        return noOfWays(corridor,0,0,dp);
    }
};