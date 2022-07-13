class Solution {
public:
    int solve(vector<int>& c,long long k,int mid)
    {
        if(!mid)
            return 1;
      long long x=0;    
        for(int i=0;i<c.size();i++)
        {
            x+=(c[i]/mid);
        }
        return x>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=0,ans=0;
       int high=*max_element(candies.begin(),candies.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(candies,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};