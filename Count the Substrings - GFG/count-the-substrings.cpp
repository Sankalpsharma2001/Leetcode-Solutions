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
        map<int,int> m;
        m[0]=1;
        int x=0;
        for(int i=0;i<s.size();i++)
        {
            if(isupper(s[i]))
            {
                x++;
            }
            else
            x--;
            if(m.find(x)!=m.end())
            {
                ans+=m[x];
            }
            m[x]++;
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