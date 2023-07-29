class Solution {
public:
  unordered_map<int, unordered_map<int, double>> dp;
    double solve(int a,int b)
    {
        if(a==0 && b)
            return 1;
        else if(a==0 && b==0)
            return 0.5;
        else if(a && b==0)
            return 0;
        if(dp[a][b]!=0) return dp[a][b];
        
        double p=0;
        p+=(0.25)*(solve(a-min(a,100),b));
        p+=(0.25)*(solve(a-min(a,75),b-min(b,25)));
        p+=(0.25)*(solve(a-min(a,50),b-min(b,50)));
        p+=(0.25)*(solve(a-min(a,25),b-min(b,75)));
        return dp[a][b]=p;
        
    }
    double soupServings(int n) {
        if(n>=4800) return 1.0;
        return solve(n,n);
    }
};