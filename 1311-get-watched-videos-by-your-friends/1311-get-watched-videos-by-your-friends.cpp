class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        queue<int> q;
        q.push(id);
        vector<bool> vis(friends.size(),false);
        vis[id]=true;
        while(!q.empty() && level>0)
        {
           int sz=q.size();
            while(sz--)
            {
                int x=q.front();
                q.pop();
                for(auto &it:friends[x])
                {
                    if(!vis[it])
                    {
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
            level--;
        }
        unordered_map<string,int> freq;
        // at level k 
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto &x:watchedVideos[x])
            {
                freq[x]++;
            }
        }
        vector<string> ans;
        vector<pair<int,string>> x;
        for(auto &c:freq)
        {
            x.push_back({c.second,c.first});
        }
        sort(x.begin(),x.end());
        for(auto &it:x)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};