class Solution {
public:
    int check(vector<int> nums,long long val)
    {
        vector<long long int> a(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>val)
            return false;
            a[i+1]-=(val-a[i]);
        }
        return (a[n-1]<=val);
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