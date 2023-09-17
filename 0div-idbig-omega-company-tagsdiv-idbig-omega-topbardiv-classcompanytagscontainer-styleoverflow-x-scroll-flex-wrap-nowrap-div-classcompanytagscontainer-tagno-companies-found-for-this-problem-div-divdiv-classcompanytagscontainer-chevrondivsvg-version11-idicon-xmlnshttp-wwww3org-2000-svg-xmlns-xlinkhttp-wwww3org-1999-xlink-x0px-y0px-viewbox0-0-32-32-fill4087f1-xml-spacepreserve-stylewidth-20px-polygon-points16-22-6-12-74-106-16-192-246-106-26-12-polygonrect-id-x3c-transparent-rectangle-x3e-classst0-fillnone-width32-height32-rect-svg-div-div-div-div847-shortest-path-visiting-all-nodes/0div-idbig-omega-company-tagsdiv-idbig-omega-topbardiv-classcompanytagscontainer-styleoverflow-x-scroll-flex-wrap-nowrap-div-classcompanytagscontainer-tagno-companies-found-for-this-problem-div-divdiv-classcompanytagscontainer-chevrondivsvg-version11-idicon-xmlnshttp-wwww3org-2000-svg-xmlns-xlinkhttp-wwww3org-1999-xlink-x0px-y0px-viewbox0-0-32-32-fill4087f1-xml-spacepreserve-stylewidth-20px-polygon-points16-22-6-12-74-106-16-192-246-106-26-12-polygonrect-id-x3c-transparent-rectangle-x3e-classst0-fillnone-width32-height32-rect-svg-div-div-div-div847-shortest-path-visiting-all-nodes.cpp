class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
       int n=graph.size();
       int check=(1<<n)-1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       set<pair<int,int>> vis; // number,mask
       for(int i=0;i<n;i++)
       {
           int mask=(1<<i);
           pq.push({0,{i,mask}}); // dis, {i,mask}
           vis.insert({i,mask});
       }
       while(!pq.empty())
       {
           auto node=pq.top();
           pq.pop();
           int dis=node.first,val=node.second.first,mask=node.second.second;
           for(auto &it:graph[val])
           {
               int newMask=mask|(1<<it);
             if(newMask==check)
                 return dis+1;
             else if(vis.count({it,newMask}))
                 continue;
              vis.insert({it,newMask});
              pq.push({dis+1,{it,newMask}}); 
           }
       }
        return 0;
    }
};