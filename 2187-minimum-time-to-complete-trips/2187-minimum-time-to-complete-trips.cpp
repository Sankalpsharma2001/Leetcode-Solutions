class Solution {
public:
    bool check(vector<int>& time, int totalTrips,long long mntime)
    {
        long long i=0,c=0;
        while(i<time.size())
        {
           long long val=time[i];
            c+=(mntime/val);
            i++;
        }
        return  c>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
       long long  low=0,high=1e14,ans=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(check(time,totalTrips,mid))
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