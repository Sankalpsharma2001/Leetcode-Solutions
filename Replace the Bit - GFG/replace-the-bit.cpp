//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int replaceBit (int n, int k)
    {
        //code here.
       int c=log2(n)+1;
       if(k>c)
       return n;
       int cnt=c-k;
       if(n&(1<<cnt))
       return n&(~(1<<cnt));
       else
       return n;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        Solution ob;
        cout <<ob.replaceBit (n, k) << endl;
    }
    return 0;
}


// } Driver Code Ends