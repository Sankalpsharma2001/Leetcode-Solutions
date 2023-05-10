class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
         int u=0,d=n-1,l=0,r=n-1;
        int c=1;
        while(u<=d and l<=r)
        {
            for(int col=l;col<=r;col++)
                mat[u][col]=c++;
            u++;
            if(u>d) break;
            for(int row=u;row<=d;row++)
                mat[row][r]=c++;
            
            r--;
            if(r<l) break;
            for(int col=r;col>=l;col--)
                mat[d][col]=c++;
            
            d--;
            if(u>d) break;
            for(int row=d;row>=u;row--)
                mat[row][l]=c++;
            l++;
            if(r<l) break;
        }
     return mat;   
    }
};