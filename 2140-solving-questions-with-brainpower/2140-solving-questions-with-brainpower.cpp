#define ll long long
class Solution {
public:
    ll maxPoints(int i,vector<vector<int>> &q,vector<ll> &dp)
    {
        int n=q.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        ll notTake=maxPoints(i+1,q,dp);
        ll take=q[i][0]+maxPoints(i+q[i][1]+1,q,dp);
        return dp[i]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<ll> dp(n+1,-1);
        return maxPoints(0,questions,dp);
    }
};