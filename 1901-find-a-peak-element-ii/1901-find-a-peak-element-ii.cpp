class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int i=0,j=mat[0].size()-1;
        int n=mat.size(),m=mat[0].size();
        while(i>=0 && i<n && j>=0 && j<m)
        {
            int u=(i-1)>=0?mat[i-1][j]:-1;
            int d=(i+1<n)?mat[i+1][j]:-1;
            int l=(j-1>=0)?mat[i][j-1]:-1;
            int r=(j+1<m)?mat[i][j+1]:-1;
            if(mat[i][j]>max({u,d,l,r}))
            {
                return {i,j};
            }
            int x=max({u,l,d,r});
            if(x==u)
            {
                i--;
            }
           else if(x==d)
            {
                i++;
            }
            else if(x==l)
            {
                j--;
            }
            else
            {
                j++;
            }
        }
        return {-1,-1};
    }
};