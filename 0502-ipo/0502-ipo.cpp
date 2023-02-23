class Solution {
public:
    static bool com(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> p;
        for(int i=0;i<profits.size();i++)
        {
            p.push_back({capital[i],profits[i]});
        }
        sort(p.begin(),p.end(),com);
        int i=0,ans=0;
       priority_queue<int> pq;
        while(k--)
        {
            while(i<profits.size() && p[i].first<=w)
            {
               pq.push(p[i].second);
                i++;
            }
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};