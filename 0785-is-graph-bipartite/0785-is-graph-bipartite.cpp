class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0); 
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(color[i]) continue;
            color[i]=1;
            q.push(i);
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int &ne:graph[node])
                {
                    if(!color[ne])
                    {
                        color[ne]=-color[node];
                        q.push(ne);
                    }
                    else if(color[ne]==color[node])
                        return false;
                }
            }
            
        }
        return true;
    }
};