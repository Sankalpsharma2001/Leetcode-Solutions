
#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
       ll sum=0;
      int j=0;
        for(int i=0;i<n;i++)
        {
            if(i<2*k) {sum+=nums[i];
            continue;}
            sum+=nums[i];
            ll avg=sum;
            ans[i-k]=avg/(2*k+1);
            sum-=nums[j++];
        }
        return ans;
        
    }
};