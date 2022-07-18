class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum=0,ans=0;
        m[0]=1;
        for(auto x:nums)
        {
            sum+=x;
            if(m.find(sum-k)!=m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};