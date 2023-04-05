class Solution {
public:
    int check(vector<int>& dist, double hour,long long speed)
    {
        double c=0;
        for(int i=0;i<dist.size();i++)
        {
            double x=(double)((double)dist[i]/(speed*1.0));
            int x1=(dist[i]/speed);
            if(x!=x1 && i!=dist.size()-1)
            {
                c+=(int(x1)+1);
            }
            else
            {
                c+=x;
            }
            if(c>hour) return false;
        }
        return c<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
         if (hour < dist.size() - 1) return -1;
        long long low=1,high=1e16,ans=-1;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(check(dist,hour,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        // cout<<ans<<" ";
        return ans>1e15?-1:ans;
    }
};