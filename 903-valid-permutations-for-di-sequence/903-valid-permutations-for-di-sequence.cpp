#define ll long long
class Solution {
public:
    vector<vector<ll>> dp;
    vector<int> vis;
    int mod=1e9+7;
    int solve(string &s,int idx,int pre)
    {
        if(idx==s.size()) return 1;
        if(dp[idx][pre]!=-1)
            return dp[idx][pre];
        ll c=0;
        if(s[idx]=='D')
        {
            for(int i=0;i<pre;i++)
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    c+=solve(s,idx+1,i)%mod;
                        vis[i]=0;
                }
                
            }
        }
        else
        {
            for(int i=pre+1;i<=s.size();i++)
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    c+=solve(s,idx+1,i)%mod;
                    vis[i]=0;
                }
            }
        }
        return dp[idx][pre]=c%mod;
    }
    int numPermsDISequence(string s) {
        vis.resize(s.size()+2,0);
        dp.resize(s.size()+2,vector<ll>(s.size()+2,-1));
        ll ans=0;
        for(int i=0;i<=s.size();i++)
        {
            vis[i]=1;
            ans+=((solve(s,0,i))%mod);
            vis[i]=0;
        }
        return ans%mod;
    }
};