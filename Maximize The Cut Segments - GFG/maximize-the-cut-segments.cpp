// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[50001];
    int solve(int n,int x,int y,int z)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int a=-1e6;
        int b=-1e6;
       int c=-1e6;
       if(n>=x)
       a=solve(n-x,x,y,z);
       if(n>=y)
       b=solve(n-y,x,y,z);
       if(n>=z)
       {
           c=solve(n-z,x,y,z);
       }
       return dp[n]=1+max({a,b,c});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
        //Your code here
        int ans=solve(n,x,y,z);
        if(ans<0) return 0;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends