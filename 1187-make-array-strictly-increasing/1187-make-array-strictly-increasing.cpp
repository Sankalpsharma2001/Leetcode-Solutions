class Solution {
public:
    int solve(vector<int>& arr1, vector<int>& arr2,int i,int j,int prev,vector<vector<int>> &dp)
    {
        if(i>=arr1.size() ) return 0;
        j=upper_bound(arr2.begin()+j,arr2.end(),prev)-arr2.begin();
        if(j==arr2.size() && prev>=arr1[i]) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=1e9,notTake=1e9;
        if(j!=arr2.size())
        {
           take=1+solve(arr1,arr2,i+1,j+1,arr2[j],dp);     
        }
        if(arr1[i]>prev)
        {
            notTake=solve(arr1,arr2,i+1,j,arr1[i],dp);
        }
        return  dp[i][j]=min(take,notTake);
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        vector<vector<int>> dp(2001,vector<int>(2001,-1));
         
        sort(arr2.begin() , arr2.end()); 
        int ans = solve( arr1, arr2, 0, 0, -1,dp ); 
        if ( ans >arr1.size() ) return -1 ; 
        return ans; 
    }
};