class Solution {
public:
    long long smaller(vector<int>& nums, int l) {
        long res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++) {
            while (i < j && nums[i] + nums[j] > l) j--;
            res += j - i;
        }
        return res;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return smaller(nums, upper) - smaller(nums, lower - 1);
        
    }
};