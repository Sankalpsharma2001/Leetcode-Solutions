class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>& locations, int cur, int finish, int fuel, vector<vector<int>> &dp)
    {
        if(fuel<0)
            return 0;
        
       
        if(dp[cur][fuel]!=-1)
            return dp[cur][fuel];
        int ans=0;
        if(cur==finish) ans++;
       //we are not returning 1 because if we return 1 at that position and our fuel is remaining than it will not take the further case where can go to other cities and return to our final city again. All that case are not calculated ,if we add one to the count then we are saying that yes we have included the current path but fuel is not 0 so we will go further in recursion to get all possible path 
        
        for(int next=0;next<locations.size();next++)
        {
            if(next!=cur)
            {
                ans=(ans%mod+solve(locations,next,finish,fuel-abs(locations[next]-locations[cur]),dp)%mod)%mod;
            }
        }
        return dp[cur][fuel]=ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       int n=locations.size();
        vector<vector<int>> dp(n+1,vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};