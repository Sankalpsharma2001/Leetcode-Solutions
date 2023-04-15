class Solution {
public:
    int maxCoins(int idx,vector<vector<int>>& piles, int k,vector<vector<int>> &dp)
    {
        if(idx==piles.size()) return 0;
       if(k==0) return 0;
     
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        int val=0;
        int temp=maxCoins(idx+1,piles,k,dp); // not take any coins from the ith piles
        for(int j=0;j<piles[idx].size() && j<k  ;j++)
        {
           
            val+=piles[idx][j];
            int temp1=maxCoins(idx+1,piles,k-(j+1),dp)+val; // take jth top coins from ith piles
                temp=max(temp,temp1);
        }
        return dp[idx][k]=temp;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return maxCoins(0,piles,k,dp);
    }
};