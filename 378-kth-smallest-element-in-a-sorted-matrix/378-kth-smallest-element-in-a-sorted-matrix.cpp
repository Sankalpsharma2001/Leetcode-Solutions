class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
       int low=matrix[0][0],high=matrix[n-1][m-1],ans=matrix[0][0];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
         int col=n-1,cnt=0;
            for(int i=0;i<n;i++)
            {
                while(col>=0 and matrix[i][col]>mid) col--;
                cnt+=col+1;
                
            }
            if(cnt<k)
            {
                ans=mid+1;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};