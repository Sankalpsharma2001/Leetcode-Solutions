class Solution {
public:
    unordered_map<string,int> dp;
    bool check(vector<int>& nums,int idx,int &n,int reqSum,int x)
    {
        if(x==0 && reqSum==0) return true;
        if(idx==n)
            return false;
        string key=to_string(idx)+" "+to_string(reqSum)+" "+to_string(x);
        if(dp.count(key))
            return dp[key];
        if(nums[idx]<=reqSum)
        {
            return dp[key]=check(nums,idx+1,n,reqSum-nums[idx],x-1) || check(nums,idx+1,n,reqSum,x);
        }
        else
        {
            return dp[key]=check(nums,idx+1,n,reqSum,x);
        }
        
        
    }
    bool splitArraySameAverage(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        for(auto &it:nums)
            sum+=it;
        // x is no of element in set 1
        for(int x=1;x<n;x++)
        {
            if((sum*x)%n==0)
            {
                int reqSum=(sum*x)/n;
                if(check(nums,0,n,reqSum,x))
                {
                    return true;
                }
            }
        }
        return false;
    }
};