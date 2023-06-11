class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,double>> p(n);
        for(int i=0;i<n;i++)
        {
             p[i].first = position[i];
            p[i].second = (double)(target - position[i])/(double)(speed[i]);
        }
        sort(p.begin(),p.end());
        int ans=1;
        double x=p.back().second;
        for(int i=n-2;i>=0;i--)
        {
            if(p[i].second>x)
            {
                x=p[i].second;
                ans++;
            }
        }
        return ans;
    }
};