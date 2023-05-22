class Solution {
public:
    class com{
        public:
        bool operator()(pair<int,int> &a,pair<int,int> &b)
        {
            if(a.first==b.first)
            {
                return a.second>b.second;
            }
            return a.first>b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &n:nums)
            mp[n]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,com> pq;
        for(auto &it:mp)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};