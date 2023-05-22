class Solution {
public:
    void func(int idx,vector<int> &v,int n,int k,vector<vector<int>> &ans)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<=n;i++)
        {   
            v.push_back(i);
            func(i+1,v,n,k,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> ans;
        vector<int> v;
        func(1,v,n,k,ans);
        return ans;
    }
};