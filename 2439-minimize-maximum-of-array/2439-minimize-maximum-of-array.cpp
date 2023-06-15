class Solution {
public:
    int check(vector<int> nums,long long val)
    {
       long long  x=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
          x+=(val-nums[i]);
            if(x<0) return false;
        }
        return x>=0;
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long low=0,high=1e10,ans=0;
        while(low<=high)
        {
           long long mid=low+(high-low)/2;
            if(check(nums,mid))
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