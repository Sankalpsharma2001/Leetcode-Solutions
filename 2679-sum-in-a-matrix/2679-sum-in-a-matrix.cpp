class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
         for(int i=0;i<nums.size();i++){
            sort(nums[i].rbegin(),nums[i].rend());
        }
        long long sum=0;
        for(int i=0;i<nums[0].size();i++){
            int val=0;
            for(int j=0;j<nums.size();j++){
                val=max(val,nums[j][i]);
            }
            sum+=val;
        }
        return sum;
    }
};