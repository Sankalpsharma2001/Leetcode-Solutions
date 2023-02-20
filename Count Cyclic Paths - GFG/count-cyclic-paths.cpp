//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   int mod=1e9+7;
   vector<vector<long long int>> dp;
    int solve(int N,char loc)
    {
        if(N==0 && loc=='O') return 1;
        if(N==0 && loc!='O') return 0;
        
        long long int ans=0;
        N-=1;
        if(loc=='O')
        {
            if(dp[N+1][0]!=-1) return dp[N+1][0]%mod;
         ans+=(solve(N,'A')%mod)%mod;
         ans+=(solve(N,'B')%mod)%mod;
         ans+=(solve(N,'C')%mod)%mod;
       return  dp[N][0]=ans%mod;
        }
        if(loc=='A')
        {
            if(dp[N+1][1]!=-1) return dp[N+1][1]%mod;
             ans+=solve(N,'O')%mod;
         ans+=(solve(N,'B'))%mod;
         ans+=(solve(N,'C'))%mod;
        return dp[N+1][1]=ans%mod;
        }
        if(loc=='B')
        {
            if(dp[N+1][2]!=-1) return dp[N+1][2]%mod;
             ans+=(solve(N,'A'))%mod;
         ans=(ans+solve(N,'O')%mod)%mod;
         ans+=(solve(N,'C'))%mod;
        return dp[N+1][2]=ans%mod;
        }
        if(loc=='C')
        {
            if(dp[N+1][3]!=-1) return dp[N+1][3]%mod;
             ans+=(solve(N,'A'))%mod;
         ans+=(solve(N,'B'))%mod;
         ans+=(solve(N,'O'))%mod;
        return dp[N+1][3]=ans%mod;
        }
       
    }
    int countPaths(int N){
        // code here 
      dp.resize(N+2,vector<long long int>(4,-1));
       
      long o=1,a=0,b=0,c=0;
      for(int i=1;i<=N;i++)
      {
          long temp1=(a+b+c)%mod;
          long temp2=(o+b+c)%mod;
          long temp3=(o+a+c)%mod;
          long temp4=(o+a+b)%mod;
          o=temp1;
          a=temp2;
          b=temp3;
          c=temp4;
      }
      return o;
       
    //   return solve(N,'O')%mod;
       
    //  vector<vector<long long int>> dp1(4,vector<long long int>(N+1,0));
    //   dp1[0][0]=1;
    //   for(int i=1;i<=N;i++)
    //   {
    //       for(int j=0;j<=3;j++)
    //       {
    //           dp1[j][i]=(dp1[j][i]%mod+dp1[(j+1)%4][i-1])%mod;
    //           dp1[j][i]=(dp1[j][i]%mod+dp1[(j+2)%4][i-1])%mod;
    //           dp1[j][i]=(dp1[j][i]%mod+dp1[(j+3)%4][i-1])%mod;
               
    //       }
    //   }
    //     return dp1[0][N]%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends