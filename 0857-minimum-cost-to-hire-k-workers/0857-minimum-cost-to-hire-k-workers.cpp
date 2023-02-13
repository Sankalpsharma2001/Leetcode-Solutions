class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> v;
        int n=wage.size();
        for(int i=0;i<wage.size();i++)
        {
            v.push_back({(double)wage[i]/quality[i]*1.0,quality[i]});
        }
        sort(v.begin(),v.end());
        // total quality*ratio is the ans
        priority_queue<int> pq; // maxHeap
        int q=0;
        for(int i=0;i<k;i++)
        {
            pq.push(v[i].second);
            q+=v[i].second;
        }
        double cost=q*v[k-1].first;
        for(int i=k;i<n;i++)
        {
           if(!pq.empty() && v[i].second<pq.top())
           {
               q-=pq.top();
               pq.pop();
               pq.push(v[i].second);
               q+=v[i].second;
           }
            cost=min(cost,q*v[i].first);
        }
        return cost;
        
    }
};