class Solution {
public:
    vector<int> solve(vector<vector<int>>& board)
    {
        vector<int> v;
        v.push_back(0);
        int n=board.size(),m=board[0].size();
        bool flag=true;
        for(int i=n-1;i>=0;i--)
        {
            if(flag)
            {
                for(int j=0;j<m;j++)
                {
                    v.push_back(board[i][j]);
                }
                flag=false;
            }
            else
            {
                for(int j=m-1;j>=0;j--)
                {
                    v.push_back(board[i][j]);
                }
                flag=true;
            }
        }
        return v;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> v=solve(board);
        int n=board.size();
        vector<int> vis(n*n+1,0),dis(n*n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            if(f==n*n) return dis[f];
            if(f>n*n) continue;
            for(int step=1;step<=6;step++)
            {
                int move=step+f;
                if(move>n*n) continue;
               
                if(v[move]!=-1)
                {
                    move=v[move];
                }
                 if(vis[move]) continue;
                    q.push(move);
                    vis[move]=1;
                    dis[move]=dis[f]+1;
                    if(move==n*n) return dis[move];
                
            }
        }
        
        return -1;
    }
};