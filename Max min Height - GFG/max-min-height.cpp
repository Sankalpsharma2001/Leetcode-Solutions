//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
     bool check(vector<int> &a,int w,int k,long long int mid,int n)
     {
         vector<int> v(n+1,0);
         long long int add=0;
         for(int i=0;i<n;i++)
         {
             add+=v[i];
             if(a[i]+add<mid)
             {
                 long long int incre=mid-add-a[i];
                 int idx=min(n,i+w);
                 v[idx]-=incre;
                 if(k<incre) return false;
                 k-=incre;
                 add=mid-a[i];
                 
             }
             
         }
         return true;
     }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            long long int low=0,high=1e14,ans=0;
            while(low<=high)
            {
                long long int mid=(low)+(high-low)/2;
                if(check(a,w,k,mid,n))
                {
                    ans=mid;
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

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends