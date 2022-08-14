class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        if(nums[0]<nums[n-1]) return nums[0];
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else if(nums[mid]<nums[high])
            {
                high=mid;
                
            }
            else
                high--;
        }
        return nums[high];
    }
};