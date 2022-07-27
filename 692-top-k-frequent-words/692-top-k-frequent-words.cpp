class Solution {
public:
   static bool com(pair<int,string> a,pair<int,string> b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> m;
        for(auto x:words)
            m[x]++;
        vector<pair<int,string>> v;
        for(auto x:m)
        {
            v.push_back(make_pair(x.second,x.first));
        }
        sort(v.begin(),v.end(),com);
        for(int i=0;i<v.size() and k--;i++)
        {
            ans.push_back(v[i].second);
            
        }
        return ans;
    }
};