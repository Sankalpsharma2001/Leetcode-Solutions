class Solution {
public:
    bool check(vector<int> &price,int k,int mid)
    {
        int c=1;
        int mn=price[0];
        for(int i=1;i<price.size() && c<k;i++)
        {
            if(price[i]-mn>=mid)
            {c++;mn=price[i];}
        }
        return c==k;
    }
    int maximumTastiness(vector<int>& price, int k) {
      sort(price.begin(),price.end());
        int low=0,high=1e9,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(price,k,mid))
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