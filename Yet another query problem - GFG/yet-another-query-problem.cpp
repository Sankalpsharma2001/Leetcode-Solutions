//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        vector<int> ans;
        
        map<int,int> m,mp;
        for(int i=N-1;i>=0;i--)
        {
            mp[A[i]]++;
            m[i]=mp[A[i]];
        }
        
        for(auto &it:Q)
        {
            int l=it[0],r=it[1],k=it[2];
            int cnt=0;
            for(int i=l;i<=r;i++)
            {
                 if(m[i]==k) cnt++;
          
            }
            ans.push_back(cnt); 
          
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends