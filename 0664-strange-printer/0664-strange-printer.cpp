class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int>> &dp)
    {
        if(i==j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
          // If s[i]==s[j] or s[j]==s[j-1],
        // then it's equivalent to printing substring s[i...j-1].
        if (s[i]==s[j]||s[j-1]==s[j]) ans=solve(i, j-1, s,dp);
         
        // If s[i]==s[i+1], it's equivalent to printing substring s[i+1...j].
        else if (s[i]==s[i+1]) ans=solve(i+1, j, s,dp);
        
         
        // If the above two conditions are not met, it means that s[i] and s[j] are different, and s[j] is also different 
        // from the character before it. In this case, we have multiple options:
        else{
            // Option 1: Print s[i...j-1] and then the character at position j, so the number of operations is f(i,j-1,s) + 1.
            ans=solve(i,j-1, s,dp)+1;
            
            // Option 2: We can try to find a character k between i and j (exclusive) such that s[k] is the same as s[j].
            // If we find such a character, it means we can print s[i...k-1] and s[k...j-1] together as one operation,
            // since both sequences will end with the same character s[j]. The number of operations would be f(i,k-1,s) + f(k,j-1,s).
            // We try all possible k values and choose the minimum among them.
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j])
                    ans=min(ans, solve(i, k-1, s,dp)+solve(k, j-1, s,dp));
            }
        }
        // Save the computed result in dp table to avoid recomputation for the same subproblems.
        return dp[i][j]=ans;
        
    }
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,dp);
    }
};