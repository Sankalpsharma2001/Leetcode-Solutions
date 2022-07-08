// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int dp[100001];
    int mod=1e9+7;
    int solve(int n)
    {
        if(n<=1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        dp[n]=solve(n-1)%mod+solve(n-2)%mod;
        return dp[n]%mod;
    }
    int countWays(int n)
    {
        memset(dp,-1,sizeof(dp));
        // your code here
        return solve(n);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends