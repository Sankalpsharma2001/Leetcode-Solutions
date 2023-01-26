class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> adj,string src,string &des,unordered_set<string> &vis,double &ans,double temp)
    {
        if(vis.find(src)!=vis.end()) return;
        vis.insert(src);
        if(src==des)
        {
            ans=temp;
            return;
        }
        for(auto &it:adj[src])
        {
            dfs(adj,it.first,des,vis,ans,temp*it.second);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            
            adj[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> vis;
            string src=queries[i][0],des=queries[i][1];
            double ans=-1.0;
            if(adj.find(src)!=adj.end())
            {
                dfs(adj,src,des,vis,ans,1.0);
            }
            res.push_back(ans);
        }
        return res;
    }
};