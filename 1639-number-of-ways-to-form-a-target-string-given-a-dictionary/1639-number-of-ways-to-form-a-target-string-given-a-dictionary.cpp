class Solution {
public:
    int mod=1e9+7;
    int ways(int i,int j,vector<string>& words, string target,vector<vector<int>> &freq,vector<vector<int>> &dp)
    {
        if(j==target.size()) return 1;
        if(i==words[0].size()) return 0;
        if(words[0].size()-i<target.size()-j) return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long ans=0;
        ans+=ways(i+1,j,words,target,freq,dp)%mod;
        ans+=(1ll*ways(i+1,j+1,words,target,freq,dp)*freq[i][target[j]-'a'])%mod;
        ans%=mod;
      return dp[i][j]=ans;
    }
    int numWays(vector<string>& words, string target) {
        
        int n=words.size(),m=words[0].size();
        vector<vector<int>> freq(m,vector<int>(26,0));
        vector<vector<int>> dp(m,vector<int>(target.size(),-1));
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               int x=words[i][j]-'a';
               freq[j][x]++;
           }
        }
        
        return ways(0,0,words,target,freq,dp);
        
    }
};