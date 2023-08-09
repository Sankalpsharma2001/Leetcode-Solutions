class Solution {
public:
    bool check(vector<int> &nums,int p,int mid)
    {
        int c=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                i++;
                c++;
            }
        }
        return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0,high=1e9+5,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(nums,p,mid))
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