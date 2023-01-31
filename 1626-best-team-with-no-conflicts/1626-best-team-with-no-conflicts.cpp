class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++)
        {
         p.push_back({ages[i],scores[i]});   
        }
        sort(p.begin(),p.end());
        int ans=0;
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++)
        {
            dp[i]=p[i].second;
         for(int j=0;j<i;j++)
         {
             if(p[i].second>=p[j].second)
             {
                 dp[i]=max(dp[i],dp[j]+p[i].second);
             }
         }
          ans=max(ans,dp[i]);  
        }
        return ans;
    }
};