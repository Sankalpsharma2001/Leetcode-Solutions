class Solution {
public:
    map<pair<int,int>,int> dp;
    int solve(vector<int> &rods,int l1,int index)
    {
        if(index==rods.size())
        {
            if(l1==0)
                return 0;
            return  dp[{l1,index}]=INT_MIN;
        }
        if(dp.count({l1,index})) return dp[{l1,index}];
        int a=rods[index]+solve(rods,l1+rods[index],index+1);
        int b=solve(rods,l1-rods[index],index+1);
        int c=solve(rods,l1,index+1);
        return dp[{l1,index}]=max({a,b,c});
    }
    int tallestBillboard(vector<int>& rods) {
      int n=rods.size();
      
        return solve(rods,0,0);
    }
};