#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,unordered_map<ll,ll>> dp;
          // dp[i][diff] will store the no. of subsequence with common difference of diff, till ith index
        
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll dif=(ll)((ll)nums[i]-(ll)nums[j]);
                ans+=dp[j][dif];
                dp[i][dif]+=dp[j][dif];
                
                dp[i][dif]++;
            }
        }
        return ans;
    }
};