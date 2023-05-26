class Solution {
public:
    int whoWin(int i,vector<int> &s,vector<int> &dp)
    {
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        a=s[i]-whoWin(i+1,s,dp);
        if(i+1<s.size())
        b=s[i]+s[i+1]-whoWin(i+2,s,dp);
        if(i+2<s.size())
        c=s[i]+s[i+1]+s[i+2]-whoWin(i+3,s,dp);
        
        return dp[i]=max({a,b,c});
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(stoneValue.size()+1,-1);
        int res=whoWin(0,stoneValue,dp);
        if (res>0)
            return "Alice";
        if(res==0) return "Tie";
        return "Bob";
    }
};