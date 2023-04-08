class Solution {
public:
    bool check(long long x1,long long y1,long long x2,long long y2,long long r)
    {
        long long d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        return d<=r*r;
    }
    void dfs(vector<vector<int>>& bombs,vector<bool> &vis,int i,int &cnt)
    {
        if(vis[i]) return;
        vis[i]=true;
        cnt++;
        int x=bombs[i][0],y=bombs[i][1],r=bombs[i][2];
        for(int j=0;j<bombs.size();j++)
        {
            int x1=bombs[j][0],y1=bombs[j][1],r1=bombs[j][2];
            if(!vis[j] && check(x,y,x1,y1,r))
            {
                dfs(bombs,vis,j,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=bombs.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            vector<bool> vis(n,false);
            dfs(bombs,vis,i,cnt);
            ans=max(ans,cnt);
        }
        return ans;
    }
};