class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end()),high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int cnt=1,sum=0;
            for(int i=0;i<n;i++)
            {
                if(sum+nums[i]<=mid)
                {
                    sum+=nums[i];
                }
                else
                    cnt++,sum=nums[i];
            }
            if(cnt<=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};