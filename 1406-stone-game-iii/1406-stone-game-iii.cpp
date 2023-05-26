class Solution {
public:
    
    string stoneGameIII(vector<int>& s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        int i=n-1;
        while(i>=0)
        {
            int a,b,c;
            a=b=c=INT_MIN;
            a=s[i]-dp[i+1];
             if(i+1<s.size())
            b=s[i]+s[i+1]-dp[i+2];
             if(i+2<s.size())
            c=s[i]+s[i+1]+s[i+2]-dp[i+3];
             dp[i]=max({a,b,c});
            i--;
        }
        int res=dp[0];
        if (res>0)
            return "Alice";
        if(res==0) return "Tie";
        return "Bob";
    }
};