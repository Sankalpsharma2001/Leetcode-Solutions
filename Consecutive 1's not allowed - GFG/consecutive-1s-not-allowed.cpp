// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    ll dp[n+10];
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=1;
	    int mod=1e9+7;
	    for(int i=2;i<=n+5;i++)
	    {
	        dp[i]=(dp[i-1]+dp[i-2])%mod;
	    }
	    return dp[n+2]%mod;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends