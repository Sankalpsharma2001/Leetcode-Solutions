class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int pre=-1,ans=0,countPre=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>right)
            {
                pre=i;
                countPre=0;
                
            }
            else if(nums[i]<=right && nums[i]>=left)
            {
                countPre=i-pre;
                ans+=countPre;
            }
            else
            {
                ans+=countPre;
            }
        }
        return ans;
    }
};