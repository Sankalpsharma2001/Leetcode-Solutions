//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int p[N+1];
        int b[N+1];
        int y[N+1];
        p[0]=colors[0][0],b[0]=colors[0][1],y[0]=colors[0][2];
        for(int i=1;i<N;i++)
        {
            int pink=colors[i][0],black=colors[i][1],yellow=colors[i][2];
            p[i]=pink+min(b[i-1],y[i-1]);
            b[i]=black+min(p[i-1],y[i-1]);
            y[i]=yellow+min(p[i-1],b[i-1]);
        }
        return min({p[N-1],b[N-1],y[N-1]});
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends