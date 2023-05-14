class Solution {
public:
    int solve(vector<int>& nums, int op, int mask, vector<int>& dp){
        int  n = nums.size();
        if(op > n/2) return 0;
        if(dp[mask] != -1) return dp[mask];
        for(int i=0;i<n;i++){
            if( (mask & (1<<i)) ) continue;
            for(int j=i+1;j<n;j++){
                if( (mask & (1<<j)) ) continue;
                
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * __gcd(nums[i],nums[j]) + solve(nums, op+1, newMask, dp);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(1<<14,-1);
        return solve(nums,1,0,dp);
    }
};