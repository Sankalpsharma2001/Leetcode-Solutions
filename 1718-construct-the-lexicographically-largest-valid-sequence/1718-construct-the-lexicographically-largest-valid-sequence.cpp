class Solution {
public:
    bool solve(int i,int n,vector<int> &ans,vector<int> &vis)
    {
        if(i>=2*(n)-1) return true;
        if(ans[i]>0) return solve(i+1,n,ans,vis);
        for(int j=n;j>=1;j--)
        {
            if(vis[j]) continue;
            if(j!=1 && ((i+j)>=ans.size() || ans[i+j]) ) continue;
            vis[j]=1;
            ans[i]=j;
            if(j!=1) ans[i+j]=j;
            if(solve(i+1,n,ans,vis)) return true;
            vis[j]=0;
            ans[i]=0;
            if(j!=1)
                ans[i+j]=0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1);
        vector<int> vis(n+1,0);
        solve(0,n,ans,vis);
        return ans;
        
    }
};