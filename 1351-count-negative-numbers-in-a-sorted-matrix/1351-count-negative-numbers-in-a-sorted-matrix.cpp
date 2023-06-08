class Solution {
public:
    int count(vector<int> &r,int n)
    {
        int low=0,high=n-1,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(r[mid]<0)
            {
               ans=mid;
               high=mid-1; 
            }
            else
            {
               low=mid+1;
            }
        }
        if(r[ans]<0)
            return n-ans;
        return 0;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        // for(vector<int> &x:grid)
        // {
        //     ans+=count(x,m);
        // }
        // return ans;
        int r=n-1,c=0;
        while(r>=0 && c<m)
        {
            if(grid[r][c]<0)
            {
                 ans+=(m-c);
               r--;
            }
            else
            {
               
                c++;
            }
        }
        return ans;
    }
};