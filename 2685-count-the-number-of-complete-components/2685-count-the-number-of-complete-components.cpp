
class Solution {
public:
    
    int dfs(int node, int &cnt,vector<vector<int>> &adj,vector<int> &vis) {
        vis[node] = 1;
        cnt++;
        int ans = adj[node].size();
        for(auto &child : adj[node]) {
            if(!vis[child]) {
                ans = ans + dfs(child, cnt,adj,vis);
            }
        }
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
      
        vector<vector<int>> adj(n+1);
        vector<int> vis(n,0);
        for(auto &v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            if(!vis[i]) {
                int ed = dfs(i,cnt,adj,vis);
                if(ed == cnt * (cnt - 1)) ans++;
            }
        }
        return ans;
    }
};