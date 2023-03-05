class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            adj[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);
        int steps=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int idx=q.front();
                q.pop();
                if(idx==n-1)
                    return steps;
                if(idx+1<n && !vis[idx+1])
                {
                    vis[idx+1]=1;
                    q.push(idx+1);
                }
                if(idx-1>=0 && !vis[idx-1])
                {
                    vis[idx-1]=1;
                    q.push(idx-1);
                }
                for(auto &it:adj[arr[idx]])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
                adj[arr[idx]].clear();
            }
            steps++;
        }
        return -1;
    }
};