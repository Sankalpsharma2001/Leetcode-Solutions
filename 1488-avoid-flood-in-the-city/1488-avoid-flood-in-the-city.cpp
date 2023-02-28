class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int> ans;
        set<int> s;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(rains[i]==0)
            {
                ans.push_back(1);
            s.insert(i);}
            else
            {
                if(m.count(rains[i]))
                {
                    auto it=s.lower_bound(m[rains[i]]);
                    if(it==s.end())return {};
                    ans[*it]=rains[i];
                    s.erase(it);
                }
                m[rains[i]]=i;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};