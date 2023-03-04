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
  void dfs(int node,int par,vector<vector<long long>> &adj,vector<bool> &isLeaf,vector<int> &A,vector<vector<long long>> &val)
  {
      bool leaf=true;
      for(auto &it:adj[node])
      {
          if(it!=par)
          {
              leaf=false;
              val[it][0]=max(val[it][0],val[node][1]+A[it]);
              val[it][1]=max(val[it][1],val[node][0]-A[it]);
              
              dfs(it,node,adj,isLeaf,A,val);
          }
      }
      
      
      isLeaf[node]=leaf;
  }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        vector<vector<long long>> adj(N+1);
        for(int i=0;i<P.size();i++){
            P[i]--;
        }
        for(int i=1;i<P.size();i++)
        {
            adj[P[i]].push_back(i);
            adj[i].push_back(P[i]);
        }
        vector<vector<long long>> val(N+1,vector<long long>(2,-1e18));
        for(int i=0;i<A.size();i++)
        {
            val[i][0]=A[i];
            
        }
        vector<bool> isLeaf(N+1,false);
        dfs(0,-1,adj,isLeaf,A,val);
        long long ans=-1e18;
        for(int i=0;i<N;i++)
        {
            if(isLeaf[i])
            {
                ans=max({ans,val[i][0],val[i][1]});
            }
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
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends