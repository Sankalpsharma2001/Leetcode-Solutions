class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                m[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        vector<bool> bus(routes.size(),0);
        unordered_map<int,bool> stop;
        q.push({src,0});
        stop[src]=1;
        while(!q.empty())
        {
            
            auto it=q.front();
            q.pop();
            if(it.first==target) return it.second;
            vector<int> v=m[it.first]; // bus option we have 
            for(int i=0;i<v.size();i++)
            {
                int curbus=v[i];
                if(bus[curbus]) continue;
                else
                {
                    vector<int> stops=routes[curbus];
                    for(int j=0;j<stops.size();j++)
                    {
                        if(stop[stops[j]]) continue;
                        else
                        {
                            q.push({stops[j],it.second+1});
                            stop[stops[j]]=1;
                        }
                    }
                    bus[curbus]=1; 
                }
               
            }
            
        }
     return -1;   
    }
};