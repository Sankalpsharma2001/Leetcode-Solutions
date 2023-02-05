class Solution {
public:
    
    int minCapability(vector<int>& nums, int k) {
         int n=nums.size();
        int low=0,high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int take=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=mid)
                {
                    take++;
                    i++;
                }
            }
            if(take>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};