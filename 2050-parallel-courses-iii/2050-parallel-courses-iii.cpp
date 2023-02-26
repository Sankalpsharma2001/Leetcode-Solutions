class Solution {
public:
    vector<vector<int>> adj; // Adjecancy List for the graph
    vector<int> in; // In-degree of every node
    vector<int> dp; // dp array to store minimun time to complete that course
    
    // dfs for solution in Top-Down manner
    int dfs(int i,vector<int> &time){
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        for(auto j:adj[i]){
            ans = max(ans,dfs(j,time));
        }
        return dp[i] = (time[i] + ans);
    }
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adj = vector<vector<int>>(n);
        in = vector<int> (n);
        dp = vector<int> (n,-1);
        
        for(auto i:relations){
            // reversing the direction while inserting in adjacency list so it will be easy to traverse
            adj[i[1] - 1].push_back(i[0] - 1);
            // incrementing in-degree
            in[i[0] - 1]++;
        }
        
        int ans = 0;
        for(int i=0;i < n;i++){
            // call dfs only if current node isn't visited and its in-degree is 0. 
            if(dp[i] == -1 && in[i] == 0){
                ans = max(ans,dfs(i,time));
            }
        }
        
        return ans;
    }
};