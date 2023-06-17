class Solution {
public:
    int dp[32][2][2];
    int digitDP(string &s,int index,int prev,int flag)
    {
        if(index==s.size())
        {
            return 1;
        }
        if(dp[index][prev][flag]!=-1) return dp[index][prev][flag];
        int range=(flag)?1:s[index]-'0';
        
        int ans=0;
        for(int i=0;i<=range;i++)
        {
            int newFlag=flag;
            if(i<range)
                newFlag=true;
            if(prev!=1 || i!=1)
            {
                ans+=digitDP(s,index+1,i,newFlag);
            }
        }
        return dp[index][prev][flag]=ans;
            
    }
    int findIntegers(int n) {
       memset(dp,-1,sizeof(dp));
        string s="";
        while(n>0)
        {
            int rem=n%2;
            s+=rem+'0';
            n/=2;
            
        }
        reverse(s.begin(),s.end());
        return digitDP(s,0,0,0);
        
    }
};