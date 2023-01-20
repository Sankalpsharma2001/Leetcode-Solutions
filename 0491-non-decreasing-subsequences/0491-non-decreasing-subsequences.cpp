class Solution {
public:
    void solve(vector<int> &nums,set<vector<int>> &res,int i,vector<int> v)
    {
        if(i>=nums.size())
        {
        if(v.size()>1)
        {
            res.insert(v);
        }
            return;
        }
        if(v.size()==0 || nums[i]>=v.back())
        {
            v.push_back(nums[i]);
            solve(nums,res,i+1,v);
            v.pop_back();
        }
        solve(nums,res,i+1,v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> v;
        solve(nums,res,0,v);
        for(auto it:res)
        {
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};