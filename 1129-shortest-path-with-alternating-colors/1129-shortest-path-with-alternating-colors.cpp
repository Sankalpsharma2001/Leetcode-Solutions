class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> length(n);
       vector<vector<int>> adjRed(n),adjBlue(n);
        // red edge is represented by 1
        
        for(auto &edge:redEdges)
        {
            adjRed[edge[0]].push_back(edge[1]);
        }
        // blue edge is represented by 2
        for(auto &edge:blueEdges)
        {
             adjBlue[edge[0]].push_back(edge[1]);
        }
        
        queue<pair<int,int>> q;
        q.push({0,1});
        q.push({0,2});
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        vector<vector<int>> vis(n,vector<int>(3,0));
        int level=0;
        while(!q.empty())
        {
           int sz=q.size(); 
            while(sz--)
            {
                
            auto t=q.front();
            int edge=t.first;
            int color=t.second;
            q.pop();
            dis[edge]=min(dis[edge],level);
            if(color==1)
            {
                for(auto &it:adjBlue[edge])
                {
                    if(!vis[it][2])
                    {
                        vis[it][2]=1;
                    q.push({it,2});
                    }
                }
            }
            else
            {
                for(auto &it:adjRed[edge])
                {
                    if(!vis[it][1])
                    {
                        vis[it][1]=1;
                    q.push({it,1});
                    }
                }
            }
                
            }
            level++;
        }
        for(int i=0;i<n;i++)
        {
            if(dis[i]==INT_MAX)
                dis[i]=-1;
        }
        return dis;
        
        
    }
};