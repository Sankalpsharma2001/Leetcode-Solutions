class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
     int sum=0;
        for(auto &it:nums) sum+=it;
        if(x>sum) return -1;
        int target=sum-x;
        int left=0,cur=0,ans=-1;
        for(int right=0;right<nums.size();right++)
        {
            cur+=nums[right];
            while(target<cur and left<=right)
            {
                cur-=nums[left++];
            }
            if(cur==target) ans=max(ans,right-left+1);
        }
        if(ans==-1) return ans;
        else return nums.size()-ans;
    }
};