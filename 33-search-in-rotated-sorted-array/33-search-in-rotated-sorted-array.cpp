class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                ans=mid;
            if(nums[mid]>=nums[low])
            {
                if(target<=nums[mid] and nums[low]<=target)
                    high=mid-1;
                else    
                 low=mid+1;
            }
            else
            {
                if(target>=nums[mid] and target<=nums[high])
                    low=mid+1; 
                else
                    high=mid-1;
            }
        }
        return ans;
    }
};