class Solution {
public:
   
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> adj(numCourses);
        for(auto &it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> vis(numCourses,vector<int>(numCourses,0));
         vector<vector<int>> reach(numCourses,vector<int>(numCourses,0));
        queue<int> q;
       for(int i=0;i<numCourses;i++)
       {
           q.push(i);
           while(!q.empty())
           {
               auto f=q.front();
               q.pop();
               for(auto &it:adj[f])
               {
                   if(vis[i][it]) continue;
                   vis[i][it]=1;
                   reach[i][it]=1;
                   q.push(it);
               }
           }
       }
        
        for(auto &it:queries)
        {
            ans.push_back(reach[it[0]][it[1]]);
        }
        return ans;
      
        
    }
};