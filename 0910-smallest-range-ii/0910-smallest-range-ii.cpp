class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mn=nums[0],mx=nums[n-1];
        int ans=mx-mn;
        for(int i=0;i<n-1;i++)
        {
            int a=nums[i]+k,b=nums[i+1]-k;
            int high=max(nums[n-1]-k,a);
            int low=min(nums[0]+k,b);
            ans=min(ans,high-low);
        }
        return ans;
    }
};