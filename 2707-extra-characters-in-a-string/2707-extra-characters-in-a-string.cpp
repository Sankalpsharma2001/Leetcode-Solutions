#define ll long long
class Solution {
public:
    
   
    int solve(int i,string &s,vector<int> &dp,unordered_set<string> &st){
        if(i>=s.length()) return 0;
        if(dp[i]!=-2) return dp[i];
        string t="";
        int ans=1+solve(i+1,s,dp,st);
        
        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(st.count(t)){
                ans=min(ans,solve(j+1,s,dp,st));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
       int n=s.size();
         unordered_set<string> st;
        for(auto &it:dictionary)
            st.insert(it);
         vector<int> dp(n+2,-2);
      
        return solve(0,s,dp,st);
    }
};