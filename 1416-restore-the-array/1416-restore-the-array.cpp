class Solution {
public:
    int mod=1e9+7;
    int count(int idx,string &s, int &k,vector<int> &dp)
    {
        if(idx==s.size())
            return 1;
        if(s[idx]=='0')
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        long long no=0;
        for(int i=idx;i<s.size();i++)
        {
           no=no*10+s[i]-'0';
            if(no>k)
                break;
            ans=(ans+count(i+1,s,k,dp)%mod)%mod;
        }
        return dp[idx]=ans;
    }
    int numberOfArrays(string s, int k) {
   int n=s.size();
        vector<int> dp(n+1,-1);
        return count(0,s,k,dp);
        
    }
};