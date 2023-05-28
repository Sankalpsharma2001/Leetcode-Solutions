class Solution {
public:
    int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
         int temp=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp);
            temp=min(temp,cost);
        }
        return dp[i][j]=temp;
    }
    int minCost(int n, vector<int>& cuts) {
         int c=cuts.size();   
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
          vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return  solve( 1,c,cuts,dp);
    }
};