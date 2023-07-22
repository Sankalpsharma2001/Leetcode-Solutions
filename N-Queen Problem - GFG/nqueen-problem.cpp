//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
vector<vector<int>> ans;
bool issafe(vector<vector<int>> &v,int x,int y,int n)
{   //check for row
    for(int row=0;row<x;row++)
    {
       if(v[row][y]==1) return false;
    }
    int row=x,col=y;
   while(row>=0 and col>=0)
   {
       if(v[row][col]==1)
       return false;
       row--;
       col--;
   }
   row=x,col=y;
   while(row>=0 and col<n)
   {
       if(v[row][col]==1)
       return false;
       row--;
       col++;
   }
   return true;
}
void nqueen(vector<vector<int>> &v,int x,int n)
{
   if(x==n)
   { vector<int> a;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(v[i][j])
           a.push_back(j+1);
       }
   }
   ans.push_back(a);
   
   return ;
   }
   for(int col=0;col<n;col++)
   {
       if(issafe(v,x,col,n))
       {
       v[x][col]=1;
       nqueen(v,x+1,n);
       
       v[x][col]=0;
       }

   }   
   return;
}
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> v(n,vector<int> (n,0));
nqueen(v,0,n);
sort(ans.begin(),ans.end());
return ans;
  
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends