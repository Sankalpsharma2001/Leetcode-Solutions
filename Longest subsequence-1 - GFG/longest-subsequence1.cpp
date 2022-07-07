// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
         if(N==1)
            return 1;
        unordered_map<int,int> m;
        int res = 1;
        for(int i=0;i<N;i++){
            if(m.count(A[i]+1) >0 || m.count(A[i]-1)>0){
                m[A[i]]=1+max(m[A[i]+1],m[A[i]-1]);
            }
            else
                m[A[i]]=1;
            res = max(res,m[A[i]]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends