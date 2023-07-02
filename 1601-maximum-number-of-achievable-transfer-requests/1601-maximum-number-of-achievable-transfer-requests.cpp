class Solution {
public:
    void solve(int idx,int cnt,int n,vector<int> &indegree,vector<vector<int>>& requests,int &ans)
    {
        if(idx==requests.size())
        {
            for(int i=0;i<n;i++)
                if(indegree[i])return;
            
            ans=max(ans,cnt);
            return;
        }
     
        solve(idx+1,cnt,n,indegree,requests,ans);
        indegree[requests[idx][0]]--;
        indegree[requests[idx][1]]++;
         solve(idx+1,cnt+1,n,indegree,requests,ans);
        indegree[requests[idx][0]]++;
        indegree[requests[idx][1]]--;
           
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n,0);
        int ans=0;
        solve(0,0,n,indegree,requests,ans);
        return ans;
    }
};