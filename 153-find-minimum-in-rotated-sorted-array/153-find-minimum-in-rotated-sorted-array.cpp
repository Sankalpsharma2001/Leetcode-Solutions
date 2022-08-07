class Solution {
public:
    int findMin(vector<int>& nums) {
          int n=nums.size();
        int l=1,h=n-2;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid-1]>nums[mid] and nums[mid]<nums[mid+1])
            {
                return nums[mid];
            }
            if(nums[mid]>nums[0])
            {
                l=mid+1;
            }
            else
                h=mid-1;
        }
        if(nums[0]>nums[n-1])
        {
            return nums[n-1];
        }
        return nums[0];
    }
};