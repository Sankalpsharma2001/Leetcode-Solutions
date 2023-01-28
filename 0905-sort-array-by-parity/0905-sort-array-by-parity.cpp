class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(j<n && nums[j]%2==0) {j++;}
            if(nums[i]%2==0 && j<i && nums[j]%2)
            {
                swap(nums[i],nums[j++]);
            }
        }
        return nums;
    }
};