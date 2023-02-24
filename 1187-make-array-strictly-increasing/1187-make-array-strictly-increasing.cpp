class Solution {
public:
    int n,m;
    long long solve(long long cur,long long left,vector<int>& arr1, vector<int>& arr2,vector<unordered_map<long long,long long>> &dp)
    {
        if(cur==arr1.size())
            return 0;
        if(dp[cur].find(left)!=dp[cur].end())
            return dp[cur][left];
       long long int res1=INT_MAX,res2;
        if(arr1[cur]>left)
        {
            res1=solve(cur+1,arr1[cur],arr1,arr2,dp);
        }
        int x=upper_bound(arr2.begin(),arr2.end(),left)-arr2.begin();
        if(x==m)
            res2=INT_MAX;
        else
            res2=solve(cur+1,arr2[x],arr1,arr2,dp);
        return dp[cur][left]=min(res1,res2+1); // res2+1 as we are swapping 
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n=arr1.size();
        m=arr2.size();
        sort(arr2.begin(),arr2.end());
        
        vector<unordered_map<long long,long long>> dp(2001);
        int val=solve(0,-1,arr1,arr2,dp);   
        
        return (val==INT_MAX)?-1:val;
    }
};