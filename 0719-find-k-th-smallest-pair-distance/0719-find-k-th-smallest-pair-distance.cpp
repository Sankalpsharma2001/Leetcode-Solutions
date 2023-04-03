class Solution {
public:
    int count(vector<int> &nums,int mid,int k)
    {
        int i=0,ans=0;
        for(int j=0;j<nums.size();j++)
        {
            while(i<nums.size() && nums[i]-nums[j]<=mid) i++;
            i--;
            ans+=(i-j);
        }
        return ans>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int low=0,high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(count(nums,mid,k))
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