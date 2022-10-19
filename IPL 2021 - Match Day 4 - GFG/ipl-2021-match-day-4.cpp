//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int countBits(int val,int arr[],int n)
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if((val&arr[i])==val)
            {
                c++;
            }
        }
        return c;
    }
    int maxAND (int arr[], int n)
    {
        // Your code here
        int ans=0;
       for(int i=31;i>=0;i--)
       {
           int c=countBits(ans|(1<<i),arr,n);
           if(c>=2)
           {
               ans=ans|(1<<i);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends