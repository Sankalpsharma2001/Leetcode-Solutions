class Solution
{
    public:
        void makecontri(int node, int par, vector<int> &cur, vector<int> &contri, int end, vector< vector< int>> &adj)
        {
            cur.push_back(node);
            if (node == end)
            {
                for (auto &it: cur)
                    contri[it]++;
                cur.pop_back();
                return;
            }
            for (auto &it: adj[node])
            {
                if (it != par) makecontri(it, node, cur, contri, end, adj);
            }
            cur.pop_back();
        }
    int dfs(int node,int par,bool prev_set,vector<int> &contri,vector<int> &price,vector<vector<int>> &adj,vector<vector<int>> &dp)
    {
        int res1=(contri[node]*price[node])/2,res2=contri[node]*price[node];
        if(dp[node][prev_set]!=-1) return dp[node][prev_set];
        for(auto &it:adj[node])
        {
            if(it!=par)
                res2+=dfs(it,node,0,contri,price,adj,dp);
        }
        if(prev_set)
            return dp[node][prev_set]=res2;
        
        for(auto &it:adj[node])
        {
            if(it!=par)
            {
                res1+=dfs(it,node,1,contri,price,adj,dp);
            }
        }
        return dp[node][prev_set]=min(res1,res2);
        
    }
    int minimumTotalPrice(int n, vector<vector < int>> &edges, vector< int > &price, vector< vector< int>> &trips)
    {
        vector<vector < int>> adj(n);
        for (auto &e: edges)
        {
            adj[e[0]].push_back(e[1]);

            adj[e[1]].push_back(e[0]);
        }
        vector<int> contri(n);

        for (auto &t: trips)
        {
            vector<int> cur;
            makecontri(t[0], -1, cur, contri, t[1], adj);
        }
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return dfs(0,-1,0,contri,price,adj,dp);
        
    }
};