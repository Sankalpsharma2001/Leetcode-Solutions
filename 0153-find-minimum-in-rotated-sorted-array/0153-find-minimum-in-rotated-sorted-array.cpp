class Solution {
public:
    int findMin(vector<int>& nums) {
       int left = 0,  right = nums.size() - 1;
        int ans=1e9;
    while(left <=  right) {
          
        int mid = (left + right)/2;
        if(nums[mid] > nums[right])
            left = mid + 1;
        else
            ans=min(ans,nums[mid]),right = mid-1;
    }
    
    return ans;
    }
};