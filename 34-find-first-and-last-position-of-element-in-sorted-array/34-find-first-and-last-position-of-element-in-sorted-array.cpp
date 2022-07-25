class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=-1,y=-1;
        if(nums.size()==0)
            return {-1,-1};
        int idx1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int idx2=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin();
       if(!binary_search(nums.begin(),nums.end(),target))    return {-1,-1};
        if(nums[idx1]!=target)
            return {-1,-1};
          idx2--;
        return {idx1,idx2};
        
    }
};