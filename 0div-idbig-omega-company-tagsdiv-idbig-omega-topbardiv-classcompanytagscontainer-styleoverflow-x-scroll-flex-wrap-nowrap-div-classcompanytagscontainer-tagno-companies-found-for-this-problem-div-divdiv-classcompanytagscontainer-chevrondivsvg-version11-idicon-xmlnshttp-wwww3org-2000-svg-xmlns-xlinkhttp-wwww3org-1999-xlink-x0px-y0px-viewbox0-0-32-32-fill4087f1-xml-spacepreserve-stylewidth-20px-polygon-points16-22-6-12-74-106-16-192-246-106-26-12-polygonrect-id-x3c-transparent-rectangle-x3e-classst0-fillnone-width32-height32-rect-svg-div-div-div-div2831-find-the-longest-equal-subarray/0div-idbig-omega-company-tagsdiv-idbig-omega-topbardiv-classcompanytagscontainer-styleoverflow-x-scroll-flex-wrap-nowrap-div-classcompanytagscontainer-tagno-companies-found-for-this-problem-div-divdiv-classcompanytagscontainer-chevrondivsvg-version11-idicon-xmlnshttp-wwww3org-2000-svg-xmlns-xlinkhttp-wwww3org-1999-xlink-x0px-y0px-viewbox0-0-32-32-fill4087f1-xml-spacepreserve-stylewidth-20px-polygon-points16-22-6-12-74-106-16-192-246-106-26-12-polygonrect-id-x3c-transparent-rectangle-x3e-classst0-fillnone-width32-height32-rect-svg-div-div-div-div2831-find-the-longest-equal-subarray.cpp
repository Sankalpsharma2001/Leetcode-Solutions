class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
         int ans=0,left=0,right=0,mxfreq=0;
        while(right<nums.size())
        {
            mp[nums[right]]++;
            mxfreq=max(mxfreq,mp[nums[right]]);
            while((right-left+1)-mxfreq>k)
            {
                mp[nums[left]]--;
                left++;
            }
            ans=max(ans,mxfreq);
            right++;
        }
        return ans;
    }
};