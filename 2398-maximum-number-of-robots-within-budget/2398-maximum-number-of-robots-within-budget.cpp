#define ll long long
class Solution {
public:
  
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        ll cost=0,j=0,robots=0;
        priority_queue<pair<ll,ll>> pq;
        for(int i=0;i<n;i++)
        {
            cost+=runningCosts[i];
            pq.push({chargeTimes[i],i});
            if(!pq.empty() && cost*(i-j+1)+pq.top().first<=budget)
            {
                robots=max(robots,i-j+1);
            }
            else
            {
                while(!pq.empty() && cost*(i-j+1)+pq.top().first>budget)
                {
                    cost-=runningCosts[j];
                    while(!pq.empty() && pq.top().second<=j) {pq.pop();}
                    j++;
                }
                 if(!pq.empty() && cost*(i-j+1)+pq.top().first<=budget)
            {
                robots=max(robots,i-j+1);
            }
            }
        }
        
        return robots;
        
    }
};