class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        int n=matches.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[matches[i][1]]++;
        
        }
        vector<int> v;
        vector<int> v1;
        for(auto &x:m)
        {
            if(x.second==1)
                v1.push_back(x.first);
            
        }
        for(int i=0;i<n;i++)
        {
            if(m[matches[i][0]]==0)
            {
                v.push_back(matches[i][0]);
                m[matches[i][0]]=1;
            }
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        
        ans.push_back(v);
        ans.push_back(v1);
        return ans;
    }
};