class Solution {
public:
    void solve(int n,int idx,vector<int> &v,int &ans)
    {
       
         if(idx==n)
             ans++;
        
        for(int i=idx;i<n;i++)
        {
            swap(v[i],v[idx]);
            if(v[idx]%(idx+1)==0 or (idx+1)%v[idx]==0)
            solve(n,idx+1,v,ans);
            swap(v[i],v[idx]);
        }
    }
    int countArrangement(int n) {
        int ans=0;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        
        solve(n,0,v,ans);
        return ans;
    }
};