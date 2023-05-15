class Solution {
public:
    void solve(int idx,int target,vector<int> &c, vector<int> v, vector<vector<int>> &ans)
    {
        if(idx==c.size())
        {
            if(target==0)
            {
                ans.push_back(v);
            }
            return;
        }
      
        if(c[idx]<=target)
        {
            v.push_back(c[idx]);
            solve(idx,target-c[idx],c,v,ans);
            v.pop_back();
        }
          solve(idx+1,target,c,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> v;
        solve(0,target,candidates,v,ans);
        return ans;
    }
};