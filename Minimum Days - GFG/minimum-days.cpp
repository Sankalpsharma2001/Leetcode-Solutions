//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        set<pair<int,int>> s;
        for(int i=0;i<N-1;i++)
        {
            if(S[i]==S[i+1])
            {
                s.insert({i,i+1});
            }
        }
        if(s.empty()) return 0;
        int ans=0;
        for(int i=0;i<P.size();i++)
        {
            S[P[i]]='?';
            int idx=P[i];
            if(idx+1<N && s.find({idx,idx+1})!=s.end())
            {
                s.erase({idx,idx+1});
            }
            if(idx>0 && s.find({idx-1,idx})!=s.end())
            {
                s.erase({idx-1,idx});
            }
            ans++;
           
            if(s.empty())
            break;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends