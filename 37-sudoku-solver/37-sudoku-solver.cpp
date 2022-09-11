class Solution {
public:
    bool check(vector<vector<char>> &board,int &row,int &col,char &ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch)
                return false;
        }
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ch)
                return false;
        }
        int r=row-row%3;
        int c=col-col%3;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                     if(board[r+i][c+j]==ch)
                         return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board,int i,int j)
    {
        if(i==9) return true;
        if(j==9)
           return solve(board,i+1,0);
        if(board[i][j]!='.')
            return solve(board,i,j+1);
        for(char c='1';c<='9';c++)
        {
            if(check(board,i,j,c))
            {
                board[i][j]=c;
                if(solve(board,i,j+1))
                    return true;;
                board[i][j]='.';
            }
        }
        return false;
     }
    void solveSudoku(vector<vector<char>>& board) {
       
        solve(board,0,0);
    }
};