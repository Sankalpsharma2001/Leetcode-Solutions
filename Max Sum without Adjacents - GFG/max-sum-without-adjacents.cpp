//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
// int dp[1000005];
// int solve(int idx,int *arr)
// {
//     if(idx==0) return arr[0];
//     if(idx<0) return 0;
//     if(dp[idx]!=-1) return dp[idx];
//     int pick=arr[idx]+solve(idx-2,arr);
//     int notPick=solve(idx-1,arr);
//     return dp[idx]=max(pick,notPick);
// }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	   // memset(dp,-1,sizeof(dp));
	   //return solve(n-1,arr);
	    
	    vector<int> dp(n+1);
	   // dp[0]=arr[0];
	   int prev=arr[0];
	   int prev2=0;
	    for(int i=1;i<n;i++)
	    {
	        int notTake=prev;
	        int take=arr[i];
	        if(i>1) take+=prev2;
	        int cur=max(notTake,take);
	        prev2=prev;
	        prev=cur;
	    }
	    return prev;
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