#define ll long long
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
        // return smaller(nums, upper) - smaller(nums, lower - 1);
        ll ans = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            auto it1 = lower_bound(nums.begin(), nums.begin()+i, lower - nums[i]);
            auto it2 = upper_bound(nums.begin(), nums.begin()+i, upper - nums[i]);
            if(it2 > it1)   ans += (it2 - it1);
        }
        
        return ans;
    }
};