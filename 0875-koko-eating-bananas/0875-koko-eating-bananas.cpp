class Solution {
public:
    bool check(vector<int>& piles, int h,int k)
    {
        int x=0;
        for(int i=0;i<piles.size();i++)
        {
          int y=piles[i]/k;
            if(piles[i]%k) y++;
            x+=y;
           if(x>h) return false;
            
        }
        return x<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=1e9,ans=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(piles,h,mid))
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