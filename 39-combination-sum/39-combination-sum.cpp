class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& c,int target,vector<int>& v,int s,int idx)
    {
        if(s>target)
            return;
        if(s==target)
        {
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<c.size();i++)
        {
            v.push_back(c[i]);
            solve(c,target,v,s+c[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> v;
        solve(candidates,target,v,0,0);
        return ans;
    }
};