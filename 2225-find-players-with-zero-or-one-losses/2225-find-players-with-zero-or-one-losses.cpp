class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        int n=matches.size();
        set<int> s;
        vector<int> vis(1e5+15,0);
        for(int i=0;i<n;i++)
        {
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);

              vis[matches[i][1]]++;
        }
        vector<int> v;
        vector<int> v1;
        for(int i=0;i<=1e5+5;i++)
        {
            if(vis[i]==1)
                v1.push_back(i);
            else if(vis[i]==0 and s.find(i)!=s.end())
                v.push_back(i);
        }
        ans.push_back(v);
        ans.push_back(v1);
        return ans;
    }
};