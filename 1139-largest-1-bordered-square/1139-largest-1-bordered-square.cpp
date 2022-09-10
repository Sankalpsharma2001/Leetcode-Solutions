class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
       vector<vector<int>> hb(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>> vb(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                if(j>0)
                {
                    hb[i][j] = hb[i][j-1]; 
                }
                if(i>0) vb[i][j] = vb[i-1][j];
                
                hb[i][j]+=1;
                vb[i][j]+=1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                int size = min(hb[i][j],vb[i][j]);
                if(size==0) continue;
                for(int k = size;k>0;k--)
                {
                    if(hb[i-k+1][j]>=k && vb[i][j-k+1]>=k)
                    {
                        ans = max(ans,k);
                    }
                }
            }
        }
        return ans*ans;
    }
};