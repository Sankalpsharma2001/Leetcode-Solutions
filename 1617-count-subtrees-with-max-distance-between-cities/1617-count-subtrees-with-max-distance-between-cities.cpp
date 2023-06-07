class Solution {
public:
    int solve(int &subtree,vector<vector<int>> &dis,int &n)
    {
              int cntN = 0 , cntE = 0 , mxd = 0;
        
        for(int i = 0 ; i<n; i++){
            if(((subtree>>i)&1) == 0)continue;
            // N:3 E:2  
            cntN++;
            for(int j = i+1; j<n; j++){
                if(((subtree>>j)&1) == 0)continue;
                
                if(dis[i][j] == 1){
                    cntE++;
                }
                mxd = max(mxd,dis[i][j]);
            }
        }
        
        if(cntN == cntE + 1){
            return mxd;
        }
        
        return -1;
    }
    vector<int> countSubgraphsForEachDiameter(int &n, vector<vector<int>>& edges) {
        vector<int> ans(n-1,0);
        vector<vector<int>> dis(15,vector<int>(15,1e9));
        for(auto &e:edges)
        {
            dis[e[0]-1][e[1]-1]=1;
            dis[e[1]-1][e[0]-1]=1;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dis[i][j]=dis[j][i]=min({dis[i][j],dis[j][i],dis[i][k]+dis[k][j]});
                }
            }
        }
        
        for(int i=0;i<(1<<n);i++)
        {
            int x=solve(i,dis,n);
            if(x>0)
            {
                ans[x-1]++;
            }
        }
        return ans;
    }
};