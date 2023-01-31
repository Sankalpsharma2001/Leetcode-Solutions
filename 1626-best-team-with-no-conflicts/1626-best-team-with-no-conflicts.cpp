class Solution {
public:
    int solve(int curIndex,int prevIndex,vector<pair<int,int>> &p,vector<vector<int>> &dp)
    {
        if(curIndex>=p.size()) return 0;
        if(dp[curIndex][prevIndex+1]!=-1) return dp[curIndex][prevIndex+1];
        int notPick=0;
        int pick=0;
        if(prevIndex==-1 || p[curIndex].second>=p[prevIndex].second)
        {
            pick=p[curIndex].second+solve(curIndex+1,curIndex,p,dp);
        }
        notPick=solve(curIndex+1,prevIndex,p,dp);
        return dp[curIndex][prevIndex+1]=max(pick,notPick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++)
        {
         p.push_back({ages[i],scores[i]});   
        }
        sort(p.begin(),p.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,-1,p,dp);
        
        
        // sort(p.begin(),p.end());
        // int ans=0;
        // vector<int> dp(n+1,0);
        // for(int i=0;i<n;i++)
        // {
        //     dp[i]=p[i].second;
        //  for(int j=0;j<i;j++)
        //  {
        //      if(p[i].second>=p[j].second)
        //      {
        //          dp[i]=max(dp[i],dp[j]+p[i].second);
        //      }
        //  }
        //   ans=max(ans,dp[i]);  
        // }
        // return ans;
    }
};