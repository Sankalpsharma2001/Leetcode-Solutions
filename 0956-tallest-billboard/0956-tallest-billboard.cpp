class Solution {
public:
   int dp[10005][21];
    int solve(vector<int> &rods,int l1,int index)
    {
        if(index==rods.size())
        {
            if(l1==0)
                return  dp[l1+5000][index]=0;
            return dp[l1+5000][index]=INT_MIN;
        }
        if(dp[l1+5000][index]!=-1) return dp[l1+5000][index];
        int a=rods[index]+solve(rods,l1+rods[index],index+1);
        int b=solve(rods,l1-rods[index],index+1);
        int c=solve(rods,l1,index+1);
        return dp[l1+5000][index]=max({a,b,c});
    }
    int tallestBillboard(vector<int>& rods) {
      int n=rods.size();
      memset(dp,-1,sizeof(dp));
        return solve(rods,0,0);
    }
};