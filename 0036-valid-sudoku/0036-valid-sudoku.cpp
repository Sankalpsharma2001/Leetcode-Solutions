class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0},col[9][9]={0},block[9][9]={0};
        for(int i=0;i<9;i++)
        {
          for(int j=0;j<9;j++)
          {
              if(board[i][j]=='.') continue;
              int num=board[i][j]-'0'-1;
              int k=(i/3)*3+j/3;
              if(row[i][num]||col[j][num] || block[k][num])
                  return false;
              row[i][num]=col[j][num]=block[k][num]=1;
                  
          }
        }
        return true;
    }
};