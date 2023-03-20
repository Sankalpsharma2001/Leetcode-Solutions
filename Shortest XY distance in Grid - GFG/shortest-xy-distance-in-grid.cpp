//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
              vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'X')
            {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int x = it.first.first;
        int y = it.first.second;
        int dist = it.second;
    
        if (grid[x][y] == 'Y')
            return dist;
            
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = x + dx[i];
            int ncol = y + dy[i];

            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and vis[nrow][ncol] == false and grid[nrow][ncol] != 'X')
            {
                q.push({{nrow, ncol}, dist + 1});
                vis[nrow][ncol] = true;
            }
        }
    }
    return -1;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends