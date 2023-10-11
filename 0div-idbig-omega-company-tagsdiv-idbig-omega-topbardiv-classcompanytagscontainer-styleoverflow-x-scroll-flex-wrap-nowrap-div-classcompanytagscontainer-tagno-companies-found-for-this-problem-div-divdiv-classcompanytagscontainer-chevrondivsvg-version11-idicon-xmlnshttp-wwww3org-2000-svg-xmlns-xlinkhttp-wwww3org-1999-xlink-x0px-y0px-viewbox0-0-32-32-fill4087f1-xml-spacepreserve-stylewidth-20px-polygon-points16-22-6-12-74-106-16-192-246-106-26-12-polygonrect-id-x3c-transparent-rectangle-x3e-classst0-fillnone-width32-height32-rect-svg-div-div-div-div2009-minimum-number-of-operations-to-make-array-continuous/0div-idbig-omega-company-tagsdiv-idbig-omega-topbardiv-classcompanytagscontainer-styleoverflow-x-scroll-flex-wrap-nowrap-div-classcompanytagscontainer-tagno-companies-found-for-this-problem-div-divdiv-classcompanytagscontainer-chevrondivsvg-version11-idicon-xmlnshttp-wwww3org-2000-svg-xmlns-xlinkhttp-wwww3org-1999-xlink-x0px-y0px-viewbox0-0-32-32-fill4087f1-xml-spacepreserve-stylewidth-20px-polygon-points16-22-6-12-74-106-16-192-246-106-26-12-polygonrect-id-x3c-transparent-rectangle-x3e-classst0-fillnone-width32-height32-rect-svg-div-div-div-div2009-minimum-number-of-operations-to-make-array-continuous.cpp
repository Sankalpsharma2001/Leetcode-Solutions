class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n=nums.size();
       int low=0,high=1e9;
        sort(nums.begin(),nums.end());
         nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
       
        int i=0,j=0,ans=1e9;
        while(i<nums.size())
        {
            while(j<nums.size() && nums[i]+n>nums[j])
            {
              j++;   
            }
            ans=min(ans,n-(j-i));
            // j-i elements are in correct place we need to change rest 
            i++;
        }
        return ans;
    }
};