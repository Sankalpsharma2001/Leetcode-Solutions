// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
long long int dp[10001];
int mod=1e9+7;
 long long int solve(int n)
 {
     if(dp[n]!=-1)
     return dp[n]%mod;
     if(n>2)
     return dp[n]=(solve(n-1)%mod+((n-1)%mod*solve(n-2)%mod)%mod)%mod;
     else
     return dp[n]=n%mod;
 }
 
    int countFriendsPairings(int n) 
    { 
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends