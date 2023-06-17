class Solution {
public:
    int dp[10][2][2];
    int digitDP(string &s,int index,int start,int flag,vector<string> &digits)
    {
        if(index==s.size())
        {
            return 1;
        }
        if(dp[index][start][flag]!=-1) return dp[index][start][flag];
          int range=(flag)?(s[index]-'0'):9;
      
        int ans=0;
        // if value is not started yet then we have two choice we can leave the current digit or start from here 
        if(!start)
        {
            ans+=digitDP(s,index+1,0,0,digits);
        }
      
        for(int i=0;i<digits.size();i++)
        {
            int val=digits[i][0]-'0';
          int newFlag = (flag) && (val == range) ? 1 : 0;
         if(val>range) continue;
         ans+=digitDP(s,index+1,1,newFlag,digits);   
        }
        return dp[index][start][flag]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        
        return digitDP(s,0,0,1,digits)-1; // removing 0
    }
};