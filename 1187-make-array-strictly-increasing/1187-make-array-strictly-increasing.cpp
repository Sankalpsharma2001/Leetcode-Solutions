class Solution {
public:
    int n,m;
    // long long solve(long long cur,long long left,vector<int>& arr1, vector<int>& arr2,vector<unordered_map<long long,long long>> &dp)
    // {
    //     if(cur==arr1.size())
    //         return 0;
    //     if(dp[cur].find(left)!=dp[cur].end())
    //         return dp[cur][left];
    //    long long int res1=INT_MAX,res2;
    //     if(arr1[cur]>left)
    //     {
    //         res1=solve(cur+1,arr1[cur],arr1,arr2,dp);
    //     }
    //     int x=upper_bound(arr2.begin(),arr2.end(),left)-arr2.begin();
    //     if(x==m)
    //         res2=INT_MAX;
    //     else
    //         res2=solve(cur+1,arr2[x],arr1,arr2,dp);
    //     return dp[cur][left]=min(res1,res2+1); // res2+1 as we are swapping 
    // }
    
    int solve ( vector<int>&arr1, vector<int>&arr2, int i, int j, int prev,vector<vector<int>> &dp  ){
        if ( i ==arr1.size()) return 0 ; 
      j=upper_bound(arr2.begin()+j,arr2.end(),prev)-arr2.begin();
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=1e9,nottake=1e9;
        if(prev>=arr1[i] && j==arr2.size()) return 1e9;
        if(j!=arr2.size())
        {
            take=1+solve(arr1,arr2,i+1,j+1,arr2[j],dp);
        }
        if(arr1[i]>prev)
        {
            nottake=solve(arr1,arr2,i+1,j,arr1[i],dp);
        }
        return dp[i][j]=min(take,nottake);
            
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//         n=arr1.size();
//         m=arr2.size();
//         sort(arr2.begin(),arr2.end());
        
//         vector<unordered_map<long long,long long>> dp(2001);
//         int val=solve(0,-1,arr1,arr2,dp);   
        
//         return (val==INT_MAX)?-1:val;
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
         
        sort(arr2.begin() , arr2.end()); 
        int ans = solve( arr1, arr2, 0, 0, -1,dp ); 
        if ( ans >arr1.size() ) return -1 ; 
        return ans; 
    }
};