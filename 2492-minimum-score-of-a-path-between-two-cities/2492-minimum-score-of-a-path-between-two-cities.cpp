#define ll long long
#define inf 1e8
#define ff first
#define ss second
class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        vector<pair<int,int>> adj[n+2];

        int m=r.size();
        int ans=inf;
for(int i=0;i<m;i++)
{
    int a=r[i][0],b=r[i][1],wt=r[i][2];
    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});
    

}
  vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1); vis[1] = 1;    //run bfs from 1
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto i: adj[node]){
                ans = min(ans, i.second);   //check for min path length
                if(vis[i.first] != 1){
                    vis[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
};