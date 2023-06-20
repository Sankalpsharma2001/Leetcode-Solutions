
#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<ll> pre(n+1,0);
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];
        for(int i=k;i<n-k;i++)
        {
            ll avg=(pre[i+k+1]-pre[i-k]);
            ans[i]=avg/(2*k+1);
        }
        return ans;
        
    }
};