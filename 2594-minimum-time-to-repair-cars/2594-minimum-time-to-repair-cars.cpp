#define ll long long 
class Solution {
public:
    bool check(vector<int>& ranks, int cars,ll mid)
    {
        ll c=0;
        for(int i=0;i<ranks.size();i++)
        {
            ll x=mid/(ranks[i]);
            ll d=sqrt(x);
            c+=d;
            
        }
        return c>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
      sort(ranks.begin(),ranks.end());
        ll low=0,high=1e18,ans=0;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(check(ranks,cars,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};