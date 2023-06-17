class Solution {
public:
    int dp[11][11][11];
    int digitDP(string num,int index,int cnt,int flag)
    {
        if(index==num.size()) return cnt;
        if(dp[index][cnt][flag]!=-1) return dp[index][cnt][flag];
        //if the number has already become smaller than the given number we can insert any digit we want between 1 to 9
        int range=(flag==1)?num[index]-'0':9;
        int ans=0;
        for(int i=0;i<=range;i++)
        {//if the digit is 1 we increase the count by 1
            int newCnt=(i==1)?cnt+1:cnt;
              //the digit at the ith position is smaller than the digit at the ith position of the number the number has already become smaller so we can set the flag as 0
         
            int newFlag=(flag && i==range)?1:0;
            ans+=digitDP(num,index+1,newCnt,newFlag);
        }
        return dp[index][cnt][flag]=ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return digitDP(s,0,0,1);
    }
};