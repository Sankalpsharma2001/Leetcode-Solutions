//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int dfs(vector<int> &arr,int i,vector<int> &vis)
    {
        int n=arr.size();
        if(i<0 || i>=n)
        return 1; // safe state
        if(vis[i]!=-1)
        return vis[i];
        vis[i]=0;
    return vis[i]=dfs(arr,i+arr[i],vis);
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n,-1);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==-1)
        dfs(arr,i,vis);
    }  
    int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1) ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends