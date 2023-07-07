//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:
int dp[1001][1001];
bool ispalindrome(string s,int i,int j)
{
    for(int k=i;k<=j;k++,j--)
    {
        if(s[k]!=s[j])
        {
            return false;
        }
        
    }
    return true;
}
int solve(string s,int i,int j)
{
    if(i>=j)
    return 0;
     if(dp[i][j]!=-1)
    return dp[i][j];
    if(ispalindrome(s,i,j))
    return 0;
   
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        // int t=1+solve(s,i,k)+solve(s,k+1,j);
        int left,right;
        if(dp[i][k]!=-1)
                left=dp[i][k];
        else
          {
              left=solve(s,i,k);
              dp[i][k]=left;
          }
        if(dp[k+1][j]!=-1)
        right=dp[k+1][j];
        else
        {right=solve(s,k+1,j);
        dp[k+1][j]=right; }
        int t=1+left+right;
        ans=min(ans,t);
    }
    return dp[i][j]=ans;
}
    int palindromicPartition(string str)
    { memset(dp,-1,sizeof(dp));
        // code here
        return solve(str,0,str.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends