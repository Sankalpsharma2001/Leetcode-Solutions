class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                idx=i-1;
                break;
            }
        }
        if(idx==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[idx]<nums[i])
            {
                swap(nums[idx],nums[i]);
                reverse(nums.begin()+idx+1,nums.end());
                return ;
            }
        }
        
        
    }
};