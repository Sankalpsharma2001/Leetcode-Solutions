//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
   
    int countSubstring(string s)
    {
        // code here
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int l=0,u=0;
            for(int j=i;j<s.size();j++)
            {
                if(islower(s[j]))
                {
                    l++;
                }
                if(isupper(s[j]))
                {
                    u++;
                }
                 if(l==u) ans++;
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends