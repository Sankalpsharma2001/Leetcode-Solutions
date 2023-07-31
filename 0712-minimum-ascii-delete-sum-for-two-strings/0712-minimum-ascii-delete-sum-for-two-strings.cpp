class Solution {
public:
    int dp[1001][1001];
    int lcs(string a,string b,int x,int y)
    {
        
        if(x==0 || y==0) return 0;
         if(dp[x][y]!=-1) return dp[x][y];
        if(a[x-1]==b[y-1])
          return  dp[x][y]=(int)a[x-1]+lcs(a,b,x-1,y-1);
        else
           return dp[x][y]=max(lcs(a,b,x-1,y),lcs(a,b,x,y-1));
        return dp[x][y];
    }
     int lcs1(string a,string b,int x,int y)
    { vector<vector<int>> dp(x+1,vector<int> (y+1,0));
       for(int i=1;i<x+1;i++)
       {
           for(int j=1;j<y+1;j++)
           {
              if(a[i-1]==b[j-1])
                  dp[i][j]=(int)a[i-1]+dp[i-1][j-1];
               else
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  
           }
       }
       return dp[x][y];
    }
    int minimumDeleteSum(string s1, string s2) {
   ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        memset(dp,-1,sizeof(dp));
        int l=lcs1(s1,s2,s1.size(),s2.size());
        int x=0;
        for(auto c:s1)
            x+=c;
        for(auto c:s2)
            x+=c;
        return x-2*l;
    }
};