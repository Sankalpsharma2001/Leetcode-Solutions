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
   int solve(vector<int>& prices,vector<vector<int>> &dp,int ind,bool buy)
    {
        if(ind==prices.size())
            return 0;
        long profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            profit=max(-prices[ind]+solve(prices,dp,ind+1,false),solve(prices,dp,ind+1,true));
        }
        else
        {
            profit=max(prices[ind]+solve(prices,dp,ind+1,true),solve(prices,dp,ind+1,false));
        }
        return dp[ind][buy]=profit;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
       return solve(prices,dp,0,true);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends