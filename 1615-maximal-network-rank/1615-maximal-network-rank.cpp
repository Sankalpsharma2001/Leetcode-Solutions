class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       
       vector<int> degree(n+1,0);
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        for(int i=0;i<roads.size();i++)
        {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
            adj[roads[i][0]][roads[i][1]]=1;
            
            adj[roads[i][1]][roads[i][0]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            { int c=degree[i]+degree[j];
                if(adj[i][j] )
                    c--;
             ans=max(ans,c);
            }
        }
        return ans;
    }
};