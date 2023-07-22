//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

/*You are required to complete this method */

class Solution{
  public:
  bool solve(int a[],int n,int k,vector<int> &vis,int sum,int s,int idx)
  {
      if(k==0) return true; // rem set only which should be div by k
      if(s>sum) return false;
      if(s==sum)
      {
          return solve(a,n,k-1,vis,sum,0,0);
          
      }
      
      for(int i=idx;i<n;i++)
      { 
          if(vis[i]==0)
          {
          vis[i]=1;
         if(solve(a,n,k,vis,sum,s+a[i],i+1)) return true;
       
          vis[i]=0;
          }
       }
       
       return false;
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++) sum+=a[i];
         if(sum%k) return false;
         sum/=k;
         vector<int> vis(n,0);
        return solve(a,n,k,vis,sum,0,0);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends