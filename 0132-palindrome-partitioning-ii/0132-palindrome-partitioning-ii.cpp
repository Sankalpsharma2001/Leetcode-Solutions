class Solution {
public:
      bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

 int f(int i, int n, string &str,vector<int> &dp) {
    //Base case:
    if (i == n) return 0;
  if(dp[i]!=-1) return dp[i];
    int minCost = INT_MAX;
    //string[i...j]
    for (int j = i; j < n; j++) {
        if (isPalindrome(str,i, j)) {
            int cost = 1 + f(j + 1, n, str,dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i]=minCost;
}
    int minCut(string s) {
        int n = s.length();
        
       
        vector<int> dp (n+1, -1);   
            
        return f(0, n, s,dp)-1;
    }
};