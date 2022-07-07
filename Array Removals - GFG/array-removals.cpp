// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            int idx=upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
            // cout<<idx<<endl;
            ans=max(ans,idx-i);
            // cout<<idx-i<<" ";
        }
        return a.size()-ans;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends