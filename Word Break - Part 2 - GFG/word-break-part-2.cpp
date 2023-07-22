//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
void solve(vector<string>& dict,int n,int idx,string s,string v,vector<string> &ans)
{  if(s.size()==idx)
  {
      v.pop_back();   
      ans.push_back(v);
      return;
  }
  else
  {
    for(int i=idx;i<s.size();i++)
    { string str=s.substr(idx,i-idx+1);
        if(find(dict.begin(),dict.end(),str)!=dict.end())
        {
          solve(dict,n,i+1,s,v+str+' ',ans);    
        }
    }
  }
}
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        
        vector<string> ans;
        string v="";
        solve(dict,n,0,s,v,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends