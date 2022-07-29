class Solution {
public:
    vector<vector<int>> ans;
    void findAllSubset(vector<int>& nums,vector<vector<int>> &ans,vector<int> v,int idx)
    {
        ans.push_back(v);
        for(int i=idx;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            findAllSubset(nums,ans,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        findAllSubset(nums,ans,v,0);
        return ans;
    }
};