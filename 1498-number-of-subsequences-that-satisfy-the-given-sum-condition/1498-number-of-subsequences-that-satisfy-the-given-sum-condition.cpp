class Solution {
public:
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        long long ans=0;
        vector<long long> pow(n+1,1);
        pow[0]=1;
        for(int i=1;i<=n;i++)
        {
            pow[i]=(pow[i-1]*2)%mod;
        }
        while(i<=j)
        {
            if(nums[i]+nums[j]<=target)
            {
                ans=(ans+pow[j-i])%mod;
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans%mod;
    }
};