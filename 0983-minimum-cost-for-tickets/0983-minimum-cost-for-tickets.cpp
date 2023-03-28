class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,1e9);
        dp[0]=0;
        for(int i=1;i<=365;i++)
        {
            if(find(days.begin(),days.end(),i)==days.end())
            {
                dp[i]=dp[i-1];
            }
            else
            {
                dp[i]=min({dp[i],dp[max(i-1,0)]+costs[0],dp[max(i-7,0)]+costs[1],
                           dp[max(i-30,0)]+costs[2]});
            }
        }
        return dp[365];
    }
};