class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int mxfre=INT_MAX,ans;
        for(auto &x:nums)
        {m[x]++;
       
        }
        for(auto &x:m)
        {
            if(x.second==1)
                return x.first;
        }
        return nums[0];
    }
};