//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void buildTree(int node,int low,int high,int seg[],int arr[])
{
    if(low==high)
    {
        seg[node]=arr[low];
        return;
    }
    int mid=low+(high-low)/2;
    buildTree(2*node+1,low,mid,seg,arr);
    buildTree(2*node+2,mid+1,high,seg,arr);
    seg[node]=(seg[2*node+1]+seg[2*node+2]);
    
}
int query(int arr[],int seg[],int idx,int low,int high,int l,int r)
{
    if(low>=l and high<=r)
    {
        return seg[idx];
    }
    if(high<l || low>r)
    return 0;
    int mid=low+(high-low)/2;
    int left=query(arr,seg,2*idx+1,low,mid,l,r);
    int right=query(arr,seg,2*idx+2,mid+1,high,l,r);
    return left+right;
}
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> ans;
        // code here
        int seg[4*n];
        buildTree(0,0,n-1,seg,arr);
        for(int i=0;i<2*q;i+=2)
        {
            int l=queries[i]-1,r=queries[i+1]-1;
            ans.push_back(query(arr,seg,0,0,n-1,l,r));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends