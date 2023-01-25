class Solution {
public:
    int n;
    vector<int> findShortestDistance(vector<int> adj[],int &node)
    {
        vector<int> dis(n+1,INT_MAX);
        queue<int> q;
        q.push(node);
        dis[node]=0;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto &it:adj[f])
            {
                if(it==-1) continue;
                if(dis[it]==INT_MAX)
                {
                dis[it]=dis[f]+1;
                q.push(it);
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int &node1, int &node2) {
       n=edges.size();
        vector<int> adj[edges.size()+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[i].push_back(edges[i]);
        }
        vector<int> dis1=findShortestDistance(adj,node1);
        vector<int> dis2=findShortestDistance(adj,node2);
        
        int dis=INT_MAX,ans=-1;
        for(int i=0;i<edges.size();i++)
        {
            if(dis>max(dis1[i],dis2[i]))
            {
                dis=max(dis1[i],dis2[i]);
                ans=i;
            }
        }
        return ans;
        
    }
};