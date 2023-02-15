class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        int edge=0;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                adj[i].push_back(leftChild[i]);
                edge++;
            }
            if(rightChild[i]!=-1)
            {
                adj[i].push_back(rightChild[i]);
                edge++;
            }
        }
        
        vector<int> indegree(n,0);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        int totalNodes=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]>1)
                return false;
            if(indegree[i]==0)
            {
                q.push(i);
                totalNodes++;
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto &it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                    totalNodes++;
                }
            }
            
        }
        if(totalNodes!=n || edge!=n-1)
            return false;
        return true;
    }
};