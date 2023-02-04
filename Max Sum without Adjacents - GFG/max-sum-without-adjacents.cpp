//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int dp[1000005];
int solve(int idx,int *arr)
{
    if(idx==0) return arr[0];
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int pick=arr[idx]+solve(idx-2,arr);
    int notPick=solve(idx-1,arr);
    return dp[idx]=max(pick,notPick);
}
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    memset(dp,-1,sizeof(dp));
	   return solve(n-1,arr);
	    
	   // vector<int> dp(n+1);
	   // if(n==1)
	   // return arr[0];
	   // if(n==2)
	   // return max(arr[0],arr[1]);
	   // dp[0]=arr[0];
	   // dp[1]=max(arr[0],arr[1]);
	   // for(int i=2;i<n;i++)
	   // {
	   //     int notTake=dp[i-1];
	   //     int take=dp[i-2]+arr[i];
	   //     dp[i]=max(notTake,take);
	   // }
	   // return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends