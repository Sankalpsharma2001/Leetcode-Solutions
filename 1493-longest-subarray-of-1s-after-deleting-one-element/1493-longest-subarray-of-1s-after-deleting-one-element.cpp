class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,cnt=0,ans=0;
        for(int j=0;j<n;j++)
        {
            cnt+=(nums[j]==0);
            while(cnt>1)
            {
                cnt-=(nums[i]==0);
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
        
    }
};