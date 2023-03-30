class Solution {
public:
    int dp[302][5][6][5][6];
    int solve(string &word,int idx,int x1,int y1,int x2,int y2,vector<pair<int, int>> &grid)
    {
        if(idx>=word.size()) return 0;
        if(dp[idx][x1][y1][x2][y2]!=-1) return dp[idx][x1][y1][x2][y2];
        int a=1e9,b=1e9;
        int x=grid[word[idx]-'A'].first,y=grid[word[idx]-'A'].second;
        a=abs(x-x1)+abs(y-y1)+solve(word,idx+1,x,y,x2,y2,grid);
        b=abs(x-x2)+abs(y-y2)+solve(word,idx+1,x1,y1,x,y,grid);
        return dp[idx][x1][y1][x2][y2]=min(a,b);
        
    }
    int minimumDistance(string word) {
         vector<pair<int, int>> grid;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<5;i++)
        { 
                if(i<4)
                {
                    for(int j=0;j<6;j++)
                    {
                        grid.push_back({i,j});
                    }
                }
                else
                {
                    for(int j=0;j<2;j++)
                    {
                        grid.push_back({i,j});
                    }
                }
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                int x1=grid[i].first,y1=grid[i].second;
                int x2=grid[j].first,y2=grid[j].second;
                ans=min(ans,solve(word,0,x1,y1,x2,y2,grid));
                
            }
        }
        return ans;
        
    }
};