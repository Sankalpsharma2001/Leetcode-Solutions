//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> parent,Rank;
  int find(int x)
  {
      if(x==parent[x])
      return x;
      return parent[x]=find(parent[x]);
  }
  void merge(int x,int y)
  {
      x=find(x);
      y=find(y);
      if(Rank[x]<Rank[y])
      {
          parent[x]=y;
      }
      else if(Rank[x]>Rank[y])
      {
          parent[y]=x;
          
      }
      else
      {
          parent[y]=x;
          Rank[x]++;
      }
  }
  void make(int n)
  {
      for(int i=0;i<=n;i++)
      {
          Rank[i]=0;
          parent[i]=i;
      }
  }
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
        parent.resize(n+1);
        Rank.resize(n+1);
        make(n);
        vector<string> ans;
         for(int i=0;i<n;i++)
         {
             int x=find(mix[i][0]);
             int y=find(mix[i][1]);
             bool flag=true;
             for(int j=0;j<m;j++)
             {
                 int a=find(danger[j][0]);
                 int b=find(danger[j][1]);
                 if((a==x && b==y) || (a==y && b==x))
                 {
                     flag=false;
                     break;
                 }
             }
             if(flag)
             {
                 merge(x,y);
                 ans.push_back("Yes");
             }
             else
             {
                 ans.push_back("No");
             }
         }
         return ans;
                                       
                                      
       }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends