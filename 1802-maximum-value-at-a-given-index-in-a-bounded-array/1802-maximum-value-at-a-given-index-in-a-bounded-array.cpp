#define ll long long
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
       
        ll r=n-1-index;
        ll l=index;
        ll low=1,high=maxSum;
        ll ans=0;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            ll sum=mid;
            ll ls=0; // sum on left
            ll rs=0; //sum on right
            ll m=mid-1;
            if(r<=m)
            {
                rs=(m*(m+1))/2-((m-r)*(m-r+1))/2;
            }
            else
            {
                rs=(m*(m+1))/2+(r-m)*1;
            }
            if(l<=m)
            {
                ls=(m*(m+1))/2-((m-l)*(m-l+1))/2;
            }
            else
            {
                ls=(m*(m+1))/2+(l-m)*1;
            }
            sum+=ls+rs;
            if(sum<=maxSum)
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