class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
            {
                ans=mid+1;
                    low=mid+1;
            }
            else
            {
           high=mid-1;
               
            }
        }
        return ans;
    }
};