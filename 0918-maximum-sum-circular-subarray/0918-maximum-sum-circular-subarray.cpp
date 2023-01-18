class Solution {
public:
    int kadane(vector<int> &nums)
    {
        int mx=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mx=max(mx,sum);
            if(sum<0)
                sum=0;
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
      int ans=kadane(nums);
        int sum=0;
        if(ans<0) return ans;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]);
            nums[i]=-nums[i];
        }
        // sum==max subarray+ remains
        // invert then 
//         total-min subarray sum
        int ans1=kadane(nums)+sum;
        return max(ans,ans1);
    }
};