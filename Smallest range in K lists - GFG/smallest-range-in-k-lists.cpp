//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
#define pipii pair<int,pair<int,int>>
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
          // val, row,col
          int mx=INT_MIN,mn=INT_MAX;
          for(int i=0;i<k;i++)
          {
               mx=max(mx,KSortedArray[i][0]);
               pq.push({KSortedArray[i][0],{i,0}});
          }
          int a=-1,b=-1;
          int range=INT_MAX;
          while(1)
          {
              auto f=pq.top();
              pq.pop();
              int val=f.first;
              int r=f.second.first;
              int c=f.second.second;
              if(mx-val<range)
              {
                  range=mx-val;
                  a=val,b=mx;
              }
               if(c+1<n)
              {
                  int val1=KSortedArray[r][c+1];
                  pq.push({val1,{r,c+1}});
                  mx=max(mx,val1);
              }
              else
              break;
          }
          return {a,b};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends