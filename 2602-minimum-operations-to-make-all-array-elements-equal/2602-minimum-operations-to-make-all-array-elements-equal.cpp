class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }
        for(auto &q:queries)
        {
            long long it=upper_bound(nums.begin(),nums.end(),q)-nums.begin();
            long long greater=pre[n]-pre[it];
            long long smaller=pre[it];
            long long x=greater-(q*(n-it));
            long long y=((it)*q)-smaller;
            ans.push_back(x+y);    
                
         
        }
       
        return ans;
    }
};