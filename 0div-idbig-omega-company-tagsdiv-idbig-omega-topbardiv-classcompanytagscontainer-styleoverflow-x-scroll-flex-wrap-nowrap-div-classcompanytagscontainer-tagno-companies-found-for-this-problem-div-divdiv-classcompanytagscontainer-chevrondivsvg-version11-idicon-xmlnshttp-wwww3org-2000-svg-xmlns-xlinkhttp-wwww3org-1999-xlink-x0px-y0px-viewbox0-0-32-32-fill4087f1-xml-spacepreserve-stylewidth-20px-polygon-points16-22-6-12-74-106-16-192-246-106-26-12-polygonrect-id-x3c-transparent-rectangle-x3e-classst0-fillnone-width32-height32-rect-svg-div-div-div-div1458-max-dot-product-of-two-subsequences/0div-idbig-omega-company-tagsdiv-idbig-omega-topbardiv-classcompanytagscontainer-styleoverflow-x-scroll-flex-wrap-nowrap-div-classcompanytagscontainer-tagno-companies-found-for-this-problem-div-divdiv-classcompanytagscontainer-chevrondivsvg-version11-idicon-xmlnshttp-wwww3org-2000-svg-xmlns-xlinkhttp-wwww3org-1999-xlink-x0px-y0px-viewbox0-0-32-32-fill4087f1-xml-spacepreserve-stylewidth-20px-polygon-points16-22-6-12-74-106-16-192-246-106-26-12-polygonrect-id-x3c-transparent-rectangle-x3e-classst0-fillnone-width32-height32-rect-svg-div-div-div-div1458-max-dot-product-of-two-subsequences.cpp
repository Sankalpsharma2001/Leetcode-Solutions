class Solution {
public:
    int solve(int i,int j,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp)
    {
         int n=nums1.size(),m=nums2.size();
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2,dp);
       int b=solve(i+1,j,nums1,nums2,dp);
       int c=solve(i,j+1,nums1,nums2,dp);
        return dp[i][j]=max({a,b,c});
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int &num : nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
       for (int &num : nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }

        // Check special cases where all elements are negative
        if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0)) {
            return max(firstMax * secondMin, firstMin * secondMax);
        }

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,nums1,nums2,dp);
            
    }
};