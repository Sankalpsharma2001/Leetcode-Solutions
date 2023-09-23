class Solution {
public:
    static bool com(string &a,string &b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
       unordered_map<string,int> dp;
       sort(words.begin(),words.end(),com); 
        int ans=1;
        for(auto &w:words)
        {
            for(int i=0;i<w.size();i++)
            {
                string t=w.substr(0,i)+w.substr(i+1);
                dp[w]=max(dp[w],dp.find(t)==dp.end() ? 1:dp[t]+1);
            }
            ans=max(ans,dp[w]);
        }
        return ans;
    }
};