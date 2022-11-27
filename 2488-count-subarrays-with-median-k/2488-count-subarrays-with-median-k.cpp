class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int idx=0;
        while(nums[idx]!=k)idx++;
        map<int,int> m;
        m[0]=1;
        int sum=0;
        for(int i=idx+1;i<n;i++)
        {
                sum+=(nums[i]<k)?-1:1;
            m[sum]++;
        }
        int ans=m[0]+m[1];
        sum=0;
        for(int i=idx-1;i>=0;i--)
        {
            sum+=(nums[i]<k)?-1:1;
            ans+=(m[-sum]+m[1-sum]);
        }
        return ans;
    }
};