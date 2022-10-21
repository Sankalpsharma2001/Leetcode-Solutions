//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        if(k>27) return 0;
        int c=0;
        int n=s.size();
        map<char,int> m;
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            
            if(j-i+1==k)
            {
                m[s[j]]++;
                if(m.size()==k-1) ans++;
                j++;
            }
            else if(j-i+1<k)
            {
                m[s[j]]++;
                j++;
            }
            else
            {
                m[s[i]]--;
               
                if(m[s[i]]==0) m.erase(s[i]);
                 i++;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends