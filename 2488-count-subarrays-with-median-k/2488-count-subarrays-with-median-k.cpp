class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        // int n=nums.size();
        // int idx=0;
        // while(nums[idx]!=k)idx++;
        // map<int,int> m;
        // m[0]=1;
        // int sum=0;
        // for(int i=idx+1;i<n;i++)
        // {
        //         sum+=(nums[i]<k)?-1:1;
        //     m[sum]++;
        // }
        // int ans=m[0]+m[1];
        // sum=0;
        // for(int i=idx-1;i>=0;i--)
        // {
        //     sum+=(nums[i]<k)?-1:1;
        //     ans+=(m[-sum]+m[1-sum]);
        // }
        // return ans;
        map<int,int> m;
        int n=nums.size();
        int sum=0,ans=0;
        m[0]++;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<k)
                sum--;
            if(nums[i]>k)
                sum++;
            if(nums[i]==k)
                flag=true;
            if(flag)
            {
                      // even  odd
                ans+=m[sum]+m[sum-1];
            }
            else
            {
                m[sum]++;
            }
        }
        return ans;
    }
};