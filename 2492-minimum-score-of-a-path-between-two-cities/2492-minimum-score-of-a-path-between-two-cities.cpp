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
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;// min heap (dis,from)
vector<int> dis(n+2,INT_MAX); // dis array
dis[1]=0;
pq.push(make_pair(0,1)); //(dis,from)
while(!pq.empty())
{
    auto p=pq.top();
    pq.pop();
    int idx=p.second;
    int w=p.first;
    for(auto &it:adj[idx])
    {
        ans=min(ans,it.second);
        if(dis[it.first]>dis[idx]+it.second)
        {
            dis[it.first]=dis[idx]+it.second;
            pq.push({dis[it.first],it.first});
        }
    }
}
 return ans;       
    }
};