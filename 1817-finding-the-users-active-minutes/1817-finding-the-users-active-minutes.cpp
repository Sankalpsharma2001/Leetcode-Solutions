class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n=logs.size();
        vector<int> ans(k,0);
        unordered_map<int,set<int>> mp;
        for(auto &it:logs)
        {
            int id=it[0],time=it[1];
            mp[id].insert(time);
        }
        for(auto &it:mp)
        {
            ans[it.second.size()-1]++;
        }
        return ans;
    }
};