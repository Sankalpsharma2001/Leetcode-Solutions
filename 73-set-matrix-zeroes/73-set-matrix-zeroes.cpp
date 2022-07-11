class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set<int> row,col;
        // vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                    // row[i]=1;
                    // col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if(row[i] || col[j])
                if(col.find(j)!=col.end() || row.find(i)!=row.end())
                {
                    matrix[i][j]=0;
                }
            }
        }
       
    }
};