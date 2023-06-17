class Solution {
public:
    int dp[23][401][2];
    int mod=1e9+7;
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(num2,min_sum,max_sum,0,0,1);
         memset(dp,-1,sizeof(dp));
         ans-=solve(num1,min_sum,max_sum,0,0,1);
         int digitSum = getSum(num1);
        if(digitSum >= min_sum && digitSum <= max_sum)
        {
            ans++;
        }
        return (ans+mod)%mod;
        
    }
    int solve( string &num, int &min_sum, int &max_sum,int index,int sum,int flag)
    {
        if(index==num.size())
        {
            return sum>=min_sum && sum<=max_sum;
        }
        if(dp[index][sum][flag]!=-1) return dp[index][sum][flag];
        int range=(flag==1)?num[index]-'0':9;
        int ans=0;
        for(int i=0;i<=range;i++)
        {
             
            int newFlag=(flag && i==range)?1:0;
            ans+=solve(num,min_sum,max_sum,index+1,sum+i,newFlag);
            ans%=mod;
        }
        return dp[index][sum][flag]=ans;
    }
     int getSum(string &num)
    {
        int sum = 0;
        
        for(int i=0;i<num.length();i++)
        {
            sum += num[i] -'0';
        }
        
        return sum;
    }
};