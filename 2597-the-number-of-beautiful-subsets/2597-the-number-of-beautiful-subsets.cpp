class Solution {
public:
    int solve(vector<int> &nums,int &k,int idx,vector<int> &v)
    {
        if(idx==nums.size()) return 0;
      int take=0;
        int notTake=solve(nums,k,idx+1,v);
        if(binary_search(v.begin(),v.end(),nums[idx]-k)==0)
        {
            v.push_back(nums[idx]);
            take=1+solve(nums,k,idx+1,v);
            v.pop_back();
        }
        return take+notTake;
    }
   
    int beautifulSubsets(vector<int>& nums, int &k) {
        int n=nums.size();
        vector<int> v;
        sort(nums.begin(),nums.end());
    
        return solve(nums,k,0,v);
           
    }
};