class Solution {
public:
    int searchPeak(vector<int>& nums,int low,int high)
    {
        if(low==high)
            return low;
        int mid=(low+high)>>1;
        if(nums[mid]>nums[mid+1])
           return searchPeak(nums,low,mid);
        return searchPeak(nums,mid+1,high);
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        long mn=-1e18,mx=1e18;
        if(n==1)
        {
            if(mn<nums[0] and nums[0]<mx)
            return 0;
         }
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<nums[mid+1])
            {
                low=mid+1;
            }
            else
                high=mid;
            
        }
        return low;
        // return searchPeak(nums,0,nums.size()-1);
    }
};