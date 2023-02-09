//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int> m;
        for(auto ch:s)
        m[ch]++;
        string str="balloon";
        int ans=INT_MAX;
        ans=min(ans,m['l']/2);
        ans=min(ans,m['o']/2);
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!='l' && str[i]!='o')
            {
                ans=min(ans,m[str[i]]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends