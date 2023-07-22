//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool safe(int node,int color[],bool graph[101][101],int V,int col)
{
    for(int i=0;i<V;i++)
    {
        if(i!=node and graph[i][node]==1 and color[i]==col)
        return false;
    }
    return true;
}
bool solve(int node,bool graph[101][101],int m,int V,int color[])
{
    if(node==V) return true;
    for(int i=1;i<=m;i++)
    {
        if(safe(node,color,graph,V,i))
        {
            color[node]=i;
            if(solve(node+1,graph,m,V,color))
            return true;
            color[node]=0;
        }
    }
    return false;
}
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
 if(solve(0,graph,m,n,color))
 return true;
 return false;
    // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends