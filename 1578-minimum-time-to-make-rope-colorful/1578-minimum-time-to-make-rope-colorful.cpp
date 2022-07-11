class Solution {
public:
    int minCost(string s, vector<int>& arr) {
        int x=arr[0],sum=arr[0];
        int n=s.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans+=(sum-x);
                x=0;
                sum=0;
            }
            sum+=arr[i];
            x=max(x,arr[i]);
        }
        ans+=(sum-x);
        return ans;
    }
};