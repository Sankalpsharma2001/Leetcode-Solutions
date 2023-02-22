class Solution {
public:
    int solve(int idx,int prePosition,string ring, string key,vector<vector<int>> &pos, vector<vector<int>> &dp)
    {
        if(idx==key.size())
            return 0;
        if(dp[prePosition][idx]!=-1)
            return dp[prePosition][idx];
        int sz=ring.size();
        int ans=INT_MAX;
        for(auto &it:pos[key[idx]-'a'])
        {
            int dis=abs(it-prePosition);
            ans=min(ans,min(dis,sz-dis)+solve(idx+1,it,ring,key,pos,dp)+1);
        }
        return dp[prePosition][idx]=ans;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(ring.size(),vector<int>(key.size(),-1));
        vector<vector<int>> pos(26); 
        for(int i=0;i<ring.size();i++)
        {
            pos[ring[i]-'a'].push_back(i);
        }
        return solve(0,0,ring,key,pos,dp);
    }
};