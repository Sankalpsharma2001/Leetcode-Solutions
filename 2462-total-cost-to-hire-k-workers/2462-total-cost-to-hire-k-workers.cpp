#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
        int i=0,j=costs.size()-1;
        int count=0;
        ll ans=0;
        while(count<k)
        {
            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && i<=j) pq2.push(costs[j--]);
            int top1=pq1.size()>0?pq1.top():INT_MAX;
            int top2=pq2.size()>0?pq2.top():INT_MAX;
            // cout<<i<<" "<<j<<" ";
            // cout<<top1<<" "<<top2<<endl;
            if(top1<=top2)
            {
                ans+=top1;
                pq1.pop();
            }
            else
            {
                ans+=top2;
                pq2.pop();
            }
            count++;
        }
        return ans;
    }
};