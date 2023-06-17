class Solution {
public:
    int dp[10][10][2][1<<10];
    int digitDP(string &s,int index,int isRepeated,int flag,int mask)
    {
        if(index==s.size())
        {
            return isRepeated;
        }
        if(dp[index][isRepeated][flag][mask]!=-1) return dp[index][isRepeated][flag][mask];
        int range=(flag)?s[index]-'0':9;
        int ans=0;
        for(int i=0;i<=range;i++)
        {
            int newFlag=(flag && i==s[index]-'0')?1:0;
            if(i==0 && mask==0) 
            ans+=digitDP(s,index+1,0,newFlag,mask);
            else if(mask&(1<<i))
            ans+=digitDP(s,index+1,1,newFlag,mask);
            else
            ans+=digitDP(s,index+1,isRepeated,newFlag,mask|(1<<i));    
        }
        return dp[index][isRepeated][flag][mask]=ans;
    }
    int countNumbersWithUniqueDigits(int n) {
         memset(dp,-1,sizeof(dp));
       
        n=pow(10,n);
        n--;
        string s=to_string(n);
        return (n)-digitDP(s,0,0,1,0)+1;
    }
};